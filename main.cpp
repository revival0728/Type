#include <iostream>
#include <algorithm>
#include "lib/Type.hpp"

using namespace std;
using namespace __Type;

int main() {
	Type a(Int), b(Double), c(Char);
	cout << a / b << '\n';
}
