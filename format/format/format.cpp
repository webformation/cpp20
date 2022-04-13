#include <format>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

int main() {
	cout << '\n';
	cout << format("Hello, C++{}!\n", "20") << '\n';
	string buffer;
	format_to(back_inserter(buffer), "Hello, C++{}!\n", "20");
	cout << buffer << '\n';
	buffer.clear();
	format_to_n(back_inserter(buffer), 5, "Hello, C++{}!\n", "20");
	cout << buffer << '\n';
	cout << '\n';
}