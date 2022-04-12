module;


export module personne;

export struct Personne;
import <iostream>;
#define TAILLE 20
using namespace std;
struct Personne
{
    string nom;
    Personne(string nom);

};
Personne::Personne(const string nom)
{
    if (nom.size() > TAILLE) {
        cout << "Le nom " << nom << " depasse les " << TAILLE << " autorises\n";
        this->nom = nom.substr(0, TAILLE);
    }
    else this->nom = nom;
}
constexpr int version = 1;