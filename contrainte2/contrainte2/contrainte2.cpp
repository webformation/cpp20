#include <iostream>
#include <concepts>
#include <ctime>
using namespace std;
// désactiver warning 4996 pour utiliser locatime sur Visual Studio;

template <class T>
concept aNom = requires (T t) {
    {t.nom } -> convertible_to<string>;
};
template <class A>
concept estAnnee = requires (A a) { 2000 - a; };

template <class T, class A> requires aNom<T>&& estAnnee<A>  struct Contact {
    T personne;
    string getNom() { return personne.nom; }
    A naissance;
    int getAge() {
        time_t maintenant = time(0);
        return 1900 + localtime(&maintenant)->tm_year - naissance;
    }
};

struct Personne {
    string nom;
};

int main()
{
    Contact<Personne, int> c1{ "Jean",2000 };
    //Contact<Personne,char*> c2 { "Jean","2000" }; // soustraction impossible
    cout << c1.getNom() << " a " << c1.getAge() << " ans\n";
}

