#include<iostream>
using namespace std;


int main() {
	int n;
	cin >> n;
	if( n/100 > 0 ) {
		for( int i=0; i<n/100; i++ ) cout << "B";
	}
	if( n/10%10 > 0 ) {
		for( int i=0; i<n/10%10; i++ ) cout << "S";
	}
	if( n%10 > 0 ) {
		for( int i=1; i<=n%10; i++ ) cout << i;
	} 
	return 0;
}
