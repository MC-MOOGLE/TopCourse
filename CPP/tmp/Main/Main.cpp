#include <iostream>
#include <sstream>

using namespace std;

int main() {
	int a;
	cout << "0 to continue, 1 to stop, other to exit program >> ";
	cin >> a;
	switch (a) {
		case 0:
			break;
		case 1:
			return 0;
			break;
		default:
			exit(0);
			break;
	}
}