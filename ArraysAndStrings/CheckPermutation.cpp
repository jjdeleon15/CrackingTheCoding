#include <iostream>
#include <string>
using namespace std;

bool checkPermutation(string a, string b) {
	int aprod = 1, bprod = 1;
	int alen = a.length(), blen = b.length();
	if (alen != blen)
		return false;
	for (int i = 0; i < alen; i++) {
		aprod *= a[i];
		bprod *= b[i];
	}
	if (aprod == bprod) 
		return true;
	else
		return false;
}


int main() {
	bool cont = true;
	string a, b, buff;
	while (cont) {
		getline(cin, a);
		getline(cin, b);
		if (checkPermutation(a, b)) {
			cout << a << " / " << b << " : IS PERMUTATION" << endl;
		} else {
			cout << a << " / " << b << " : NOT PERMUTATION" << endl;
		}
		cin >> cont;
		getline(cin, buff);
	} 
}