#include <iostream>
#include <iomanip>
using namespace std;

void judge( int num);
int increase( int num);
int decrease( int num);

int main() {
	int n;
	cin >> n;
	judge( n );
	return 0;
}

void judge( int num) {
	int a = increase( num);
	int b = decrease( num);
    cout << setfill('0') << setw(4) << b << "-"
         << setfill('0') << setw(4) << a << "="
         << setfill('0') << setw(4) << b-a << endl;
    if( (b-a) == 0 || (b-a) == 6174) return;
    judge(b-a);
}

int increase( int num) {
	int a[4];
	for( int i=0; i<4; ++i) {
		a[i] = num%10;
		num /= 10;
	}
	for( int i=0; i<3; ++i)
		for( int j=0; j<3-i; ++j)
			if( a[j] > a[j+1]) {
				int t = a[j];
				a[j]  = a[j+1];
				a[j+1]= t;
			}
	return ( a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3] );
}
int decrease( int num) {
	int a[4];
	for( int i=0; i<4; ++i) {
		a[i] = num%10;
		num /= 10;
	}
	for( int i=0; i<3; ++i)
		for( int j=0; j<3-i; ++j)
			if( a[j] < a[j+1]) {
				int t = a[j];
				a[j]  = a[j+1];
				a[j+1]= t;
			}
	return ( a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3] );
}
