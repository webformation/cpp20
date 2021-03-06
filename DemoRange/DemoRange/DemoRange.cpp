#include <iostream>
#include <vector>
#include <ranges>
using namespace std;
using namespace std::ranges;



int main()
{
    vector<int> entiers{ 1,2,3,4,5,6,7,8 };
    auto pair = [](auto x) { return x % 2 == 0; };
    auto carre = [](auto x) {return x * x; };
    for (auto i : entiers | views::filter(pair) | views::transform(carre)) {
        cout << i << ' ';
    }
}

