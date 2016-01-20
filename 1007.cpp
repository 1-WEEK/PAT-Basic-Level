#include<iostream>
#include<math.h>
using namespace std;

bool isPrime( int num ) {
	int flag = 0;
	for( int i=2; i<=sqrt(num); i++ ) {
		if( num%i==0 ) { flag = 1;break;}
	}
	if( flag==0 ) return true;
	else return false;
}

int main() {
	int n;
	cin >> n;
	int a[n], j=1, count=0;
	a[0] = 2;
	for( int i=3; i<=n; i+=2 ) {
		if( isPrime(i) )
			a[j++]=i;
	}
	for( int i=0; i<j-1; i++ ) {
		if( a[i+1] - a[i] == 2 ) ++count;
	}
	cout << count;
	return 0;
}
