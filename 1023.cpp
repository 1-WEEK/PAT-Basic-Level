#include <iostream>
using namespace std;

int main() {
	int a[10];
	string s;
	for( int i=0; i<10; ++i) cin >> a[i];
	for( int i=1; i<10; ++i)
		if( a[i]) {
			s += i + '0';
			--a[i];
			break;
		}
	for( int i=0; i<10; ++i)
		while( a[i]) {
			s += i + '0';
			--a[i];
		}
	cout << s;
	return 0;
}
