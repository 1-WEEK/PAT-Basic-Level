#include<iostream>
#include<iomanip>
using namespace std;

int A1( int[], int );
int A2( int[], int );
int A3( int[], int );
float A4( int[], int );
int A5( int[], int );

int main() {
	int x;
	cin >> x;
	int a[x], n = 0, a1, a2, a3, a5;
	float a4;
	for(;;) {
		cin >> a[n++];
		if( cin.get() == '\n') break;
	}
	a1 = A1( a, n);
	a2 = A2( a, n);
	a3 = A3( a, n);
	a4 = A4( a, n);
	a5 = A5( a, n);
	
	if( a1 == -1) cout << "N "; 
    else cout << a1 << " ";
    if( a2 == -1) cout << "N "; 
    else cout << a2 << " ";
    if( a3 == -1) cout << "N "; 
    else cout << a3 << " ";
    if( a4 == -1) cout << "N "; 
    else cout << fixed << setprecision(1) << a4 << " ";
    if( a5 == -1) cout << "N"; 
    else cout << a5;
	return 0;
}

int A1( int a[], int n) {
	int sum = 0;
	for( int i = 0; i < n; ++i)
		if( a[i] % 10 == 0 ) sum += a[i];
	if( sum == 0) return -1;
	return sum;
}

int A2( int a[], int n) {
	int flag = 0, sum = 0, num = 1;
	for( int i = 0; i < n; ++i) {
		if( a[i] % 5 == 1) {
			sum += num * a[i];
			num = -num;
			flag = 1;
		}
	}
	if( flag == 0 ) return -1;
	return sum;
}

int A3( int a[], int n) {
	int count = 0;
	for( int i = 0; i < n; ++i)
		if( a[i] % 5 == 2) ++count;
	if( count == 0) return -1;
	return count;
}

float A4( int a[], int n) {
	float sum = 0, count = 0;
	for( int i = 0; i < n; ++i) {
		if( a[i] % 5 == 3) {
			sum += a[i];
			++count;
		}
	}
	if( count == 0) return -1;
	return sum/count;	
}

int A5( int a[], int n) {
	int max = 0;
	for( int i = 0; i < n; ++i)
		if( a[i] % 5 == 4 && a[i] > max) max = a[i];
	if( max == 0) return -1;
	return max;
}
