#include <iostream>
#include <cctype>
#include <string>
using namespace std;

/*
	Assumes that string input is all in lower case
*/

/*
	One change can be an insertion, deletion, or replacement of one character
	Does not allow for rearrangment 
*/
bool oneChangeAway(string a, string b) {
	int alen = a.length(), blen = b.length();
	int dif = alen - blen;
	int smaller = min(alen, blen);
	bool skipped;
	int i, j;
	switch(dif) {
	case 1:
		swap(a, b);
		swap(alen, blen);
	case -1: //Finding insertion, a is smaller string now
		i = 0, j = 0;
		while (i < smaller) {
			if (a[i] != b[j]) {
				if (skipped)
					return false;
				else 
					skipped = true;
			} else {
				i++;
			}
			j++;
		}
		break;
	case 0:
		i = 0;
		while (i < alen) {
			if (a[i] != b[i]) {
				if (skipped) {
					return false;
				} else {
					skipped = true;
				}
			}
			i++;
		}
		break;
	default:
		return false;
	}
	return true;
}

int main() {
	string a, b;
	while (true) {
		cout << "Enter a word:\n";
		getline(cin, a);
		cout << "Another one:\n";
		getline(cin, b);
		if (oneChangeAway(a,b)) {
			cout << "Yes\n\n";
		} else {
			cout << "Nope\n\n";
		}
	} 
}