#include <iostream>
#include <string>
using namespace std;

bool isUnique(string s) {
	int prod = 1;
	int len = s.length();
	int c;
	for (int i = 0; i < len; i++) {
		c = s[i];
		if (prod % c == 0)
			return false;
		else
			prod *= c;
	}
	return true;
}


int main() {
	bool cont = true;
	string s;
	while (cont) {
		getline(cin, s);
		if (isUnique(s)) {
			cout << s << " : UNIQUE" << endl;
		} else {
			cout << s << " : NOT UNIQUE" << endl;
		}
		cin >> cont;
		getline(cin, s);
	} 
}