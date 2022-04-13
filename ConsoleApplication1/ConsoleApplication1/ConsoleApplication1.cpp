import <iostream>;

using namespace std;
extern  int version_interne;
import societe;

int main()
{
   Personne p1("Jean Dupond");
    cout << p1.nom << endl;
    Societe s1("A la belle enseigne de Grenoble et du Dauphine", p1);
    cout << s1.nom << endl;
    cout << version << endl;
    cout << version_interne << endl;
    return 0;
}
