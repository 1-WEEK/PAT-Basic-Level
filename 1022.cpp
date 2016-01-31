#include <iostream>
using namespace std;

int main() {
	int a, b, d;
	string s;
	cin >> a >> b >> d;
	a += b;
	if(!a) cout <<"0";
	while( a) {
		s += a % d + '0';
		a /= d;
	}
	for( int i=s.length()-1; i>=0; --i) cout << s[i];
	return 0;
}
