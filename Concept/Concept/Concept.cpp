#include <iostream>
using namespace std;
template <typename T> concept Entier = std::is_integral<T>::value;

Entier auto pgcd(Entier auto a, Entier auto b) {
    if (b == 0) return a;
    else return pgcd(b, a % b);
}
int main()
{
   cout << pgcd(10,12) << "\n"; // ok
   // cout << pgcd(10., 12) << "\n"; // erreur de compilation
}
