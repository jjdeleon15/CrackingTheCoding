#include <iostream>
using namespace std;



int waysUp(int steps){
	if (steps == 0) {//Found a solution
		return 1;
	} else if (steps < 0) {//skipped end
		return 0;
	} else {
		return waysUp(steps - 1) + waysUp(steps - 2) + waysUp(steps - 3);
	}
}

bool cont() {
	cout << "Continue? :";
	string s;
	getline(cin, s);
	if (s == "yes" || s == "true" || s == "1" || s == "y")
		return true;
	else 
		return false;
}

int main() {
        int steps;
	string buff;
        do {
                cin >> steps;
		getline(cin, buff);
		cout << "There are " << waysUp(steps) << " the stairs\n";	
        } (cont();
}

