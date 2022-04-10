#include <iostream>
#include <concepts>
using namespace std;

template <class T> 
concept aNom = requires (T t) {
    {t.nom } -> convertible_to<string>;
};
template <class T> requires aNom<T> struct Contact{
    T personne;
    string getNom() { return personne.nom; }
};

struct Personne {
    string nom;
};
struct People {
    string name;
};
struct Robot {
    int nom;
};
int main()
{
    Contact<Personne> c1{ "Jean" };
//    Contact<People> c2{ "John" }; // pas de champ nom
//    Contact<Robot> c3{ 2459 }; // le champ nom n'est pas convertible en string
    cout << c1.getNom() << "\n";
}

