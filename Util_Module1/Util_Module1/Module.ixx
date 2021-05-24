module;

#include <iostream>
#include <vector>

export module agenda;

using namespace std;

export struct personne {
    vector<personne> enfants;
    string nom;
    personne(string nom) : nom{ nom } {}
    template <typename... T> personne(string nom, T... enfants) : nom{ nom }, enfants{ enfants... } {}
};