#include<iostream>
using namespace std;

int main() {
	char A[11], B[11], DA, DB;
	int PA=0, PB=0, flag=1; 
	cin >> A >> DA >> B >> DB;
	for(int i=0; i<10 || A[i]=='\0'; ++i)
		if( A[i]==DA ) {
			PA += ( DA - '0')* flag;
			flag *= 10;
		}
	flag = 1;
	for(int i=0; i<10; ++i)
	if( B[i]==DB ) {
		PB += ( DB - '0')* flag;
		flag *= 10;
	}
	cout << PA+PB;
	return 0;
}
