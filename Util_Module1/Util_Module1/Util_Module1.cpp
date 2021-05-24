import <iostream>;

import agenda;

using namespace std;

int main() {
    personne p1("Jean");
    personne p2("Marc", p1);
    cout << p2.enfants[0].nom << "\n";
    return 0;
}