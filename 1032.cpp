#include <iostream>
using namespace std;

int main (){
	int school[100001] = {0}, n, max = 0;
	cin >> n;
	for( int i=0; i<n; ++i) {
		int j, num;
		cin >> j >> num;
		school[j] += num;
		if( j>max) max = j;
	}
	int max1 = 0,
		max2 = 0;
	for( int i=1; i<=max; ++i) {
		if( school[i] > max1) {
			max1 = school[i];
			max2 = i;
		}
	}
	cout << max2 << " " << max1;
	return 0;
}
