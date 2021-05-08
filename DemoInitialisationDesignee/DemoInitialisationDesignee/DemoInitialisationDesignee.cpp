#include <iostream>
using namespace std;

struct Point {
    int x;
    int y = 2;
    int z;
};
ostream&  operator << (ostream& o, const Point& p) {
    o << p.x << "," << p.y << "," << p.z;
    return o;
}
int main()
{
    Point P1{ 10,10,0 }; // C++ 11
    Point P2{ .x = 10,.y = 10,.z = 10 };// C++ 20
    Point P3{ .x = 10,.z = 10 };// C++ 20 ok
    Point P4{ .x = 10};// C++ 20 licite, mais z pas initialisé
    //Point P5 { .y = 10,.x = 10,.z = 10 } // erreur compilation
    //Point P5{ .x = 10.3,.y = 10,.z = 10 };// erreur compilation
    cout << P1 << "\n";
    cout << P2 << "\n";
    cout << P3 << "\n";
    cout << P4 << "\n";
}

