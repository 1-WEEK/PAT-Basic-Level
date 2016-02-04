#include <iostream>
using namespace std;
void print( int n, char c) {
	for( int i = 0; i <( n + 1 )/ 2; ++i) {
		for( int j = 0; j < i; ++j) 
			cout << " ";
		for( int j = 0; j < n - i * 2; ++j)
			cout << c;
		cout << endl;
	}
	for( int i = 1; i <( n + 1 )/ 2; ++i) {
		int t =( n - i)/ 2;
		for( int j = 0; j < ( n - 1 )/ 2 - i; ++j)
			cout << " ";
		for( int j = 1; j <= 2 * i + 1; ++j)
			cout << c;
		cout << endl; 
	}
}
int main() {
	int n;
	char c;
	cin >> n >> c;
	int temp;
	for( int i = 1, sum, flag = 0;; i += 2) {
		sum = ( i * i + 2 * i - 1 )/ 2;
		if( n  < sum) {
			flag = 1;
			n = i-2;
			break;
		}
		temp = n - sum;
	}
	print(n, c);
	cout << temp;
	return 0;
}
