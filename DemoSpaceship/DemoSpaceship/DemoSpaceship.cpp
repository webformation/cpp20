#include <iostream>
using namespace std;
struct Entier {
    int i;
    explicit Entier(int i) : i{ i } {};
    auto operator <=>(const Entier & e) const = default;
    auto operator<=>(const int& i) const {
        return this->i <=> i;
    }
};

int main()
{
    Entier i1{ 1 };
    Entier i5{ 5 };
    cout << boolalpha << (i1 < i5) << endl;
    cout << boolalpha << (i1 < 10) << endl;
}


