#include<iostream>
#include<math.h>
using namespace std;

bool isPrime( int );

int main() {
	int M, N, n = 2, countP = 0, count = 0, flag = 0;
	cin >> M >> N;
	while ( countP < N) {
		if( isPrime( n )) {
			++countP;
			if( countP >= M) {
				++count;
				if( flag == 0) {
					cout << n;
					flag = 1;
				}
				else cout << " " << n;
				if( count % 10 == 0) {
					flag = 0;
					cout << endl;
				}
			}
		}
		++n;
	}
	return 0;
}

bool isPrime ( int n) {
	int flag = 1;
	for( int i = 2; i <= sqrt(n); ++i)
		if( n % i == 0) { flag = 0; break;}
	if( flag == 1) return true;
	else return false;
}
