#include <iostream>
using namespace std;


int main() {
	string right, woring;
	cin >> right;
	cin >> woring;
	string s = "";
	
	for( int i = 0; i<right.length(); ++i) {
		int flag = 0;
		for( int j = 0; j<woring.length(); ++j)
			if( right[i] == woring[j]) {
				flag = 1;
				break;
			}
		if( flag == 0 ) {
			int flag1 = 0;
			if( right[i] <='z' && right[i] >='a'){
				right[i] -= 'a' - 'A';
			}
			for( int j=0; j<s.length(); ++j) {
				if( s[j] == right[i])
					flag1 = 1;
			}
			if( flag1 == 0) s += right[i];
		}
	}
	cout << s;
	return 0;
}
