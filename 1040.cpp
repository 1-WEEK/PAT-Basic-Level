#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	int numP   = 0,
		numPA  = 0,
		numPAT = 0;
	for(int i=0; i<str.length(); ++i) {
		if(str[i] == 'P')
			++numP;
		else if(str[i] == 'A')
			numPA = (numPA + numP)% 1000000007;
		else
			numPAT = (numPAT + numPA)% 1000000007;
	}
	cout << numPAT;
	return 0;
}
