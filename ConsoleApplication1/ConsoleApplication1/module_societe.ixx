module;
constexpr int version_interne = 1;

export module societe;
import <iostream>;
export import personne;

#define TAILLE 80
using namespace std;

export struct Societe
{
    string nom;
    Personne directeur;
    Societe(string nom, Personne directeur);

};

constexpr int version = 2;

Societe::Societe(const string nom, Personne directeur) : directeur(directeur)
{
    if (nom.size() > TAILLE) {
        cout << "Le nom " << nom << " depasse les " << TAILLE << " autorises\n";
        this->nom = nom.substr(0, TAILLE);
    }
    else this->nom = nom;
}



