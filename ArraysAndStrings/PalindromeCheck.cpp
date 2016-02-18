#include <iostream>
#include <cctype>
#include <string>
using namespace std;


bool isPal(string s) {
	int letters[26] = {0};
	int len = s.length();
	int i;
	char letter;
	for (i = 0; i < len; i++) {
		letter = s[i];
		if (isalpha(letter)) {
			letters[tolower(letter) - 'a']++;
		}
	}

	bool foundOdd;
	for (i = 0; i < 26; i++) {
		if (letters[i] % 2 == 1) {
			if (foundOdd) {
				return false;
			} else {
				foundOdd = true;
			}
		}
	}
	return true;
}

int main() {
	string s;
	while (true) {
		cout << "Enter phrase or sentence:\n";
		getline(cin, s);
		if (isPal(s)) {
			cout << "Yes\n\n";
		} else {
			cout << "Nope\n\n";
		}
	} 
}