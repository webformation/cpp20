#include <iostream>
#include <coroutine>

// Vs 2019 :  d�sactiver le warning 4716 pour compiler 

using namespace std;

struct Generator {
    struct Promise;

    // compiler looks for promise_type
    using promise_type = Promise;
    coroutine_handle<Promise> coro;

    Generator(coroutine_handle<Promise> h) : coro(h) {}

    ~Generator() {
        if (coro)
            coro.destroy();
    }

    // get current value of coroutine
    int value() {
        return coro.promise().val;
    }

    // advance coroutine past suspension
    bool next() {
        coro.resume();
        return !coro.done();
    }

    struct Promise {
        // current value of suspended coroutine
        int val;

        // called by compiler first thing to get coroutine result
        Generator get_return_object() {
            return Generator{ coroutine_handle<Promise>::from_promise(*this) };
        }

        // called by compiler first time co_yield occurs
        suspend_always initial_suspend() {
            return {};
        }

        // required for co_yield
        suspend_always yield_value(int x) {
            val = x;
            return {};
        }

        // called by compiler for coroutine without return
         suspend_never return_void() noexcept(true)  {
             return;
        } 

        // called by compiler last thing to await final result
        // coroutine cannot be resumed after this is called
        suspend_always final_suspend() noexcept(true) {
            return {};
        }
        suspend_always unhandled_exception() {}
    };

};

Generator myCoroutineFunction(int n) {

    for (int i = 0; i < n; ++i) {
        co_yield i;
    }

}

int main()
{
    int n = 10;

    Generator myCoroutineResult = myCoroutineFunction(n);

    for (int i = 0; i < n; ++i) {
        myCoroutineResult.next();
        printf("%d ", myCoroutineResult.value());
    }

    return 0;
}