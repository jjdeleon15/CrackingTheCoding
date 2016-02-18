#include <iostream>
#include <string>
using namespace std;

void urlify(string &s, int len) {
	if (len < 3)
		return;
	int ptr = len - 1;
	while (s[ptr] == ' ')
		ptr--;
	int end = len - 1;
	while (ptr > -1) {
		if (s[ptr] != ' ') {
			s[end] = s[ptr];
		} else {
			s[end--] = '0';
			s[end--] = '2';
			s[end] = '%';
		}
		end--;
		ptr--;
	}
}

int main() {
	string s;
	int len;
	while (true) {
		cout << "Enter phrase or sentence:\n";
		getline(cin, s);
		cout << "Enter length of string: ";
		cin >> len;
		cout << "Got length of " << len << endl;
		urlify(s, len);
		cout << s << endl;
	} 
}