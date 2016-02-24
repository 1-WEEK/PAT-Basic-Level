#include <iostream>
using namespace std;

int main() {
	int n, h;
	char c;
	cin >> n >> c;
	h = n/2;
	if( n%2 != 0) ++h;
	for(int i=0; i < h; ++i) {
		for(int j=0; j < n; ++j) {
			if( i == 0 || i == h - 1 || j == 0 || j == n - 1)
				cout << c;
			else cout << " ";
		}
		if(i != h - 1)
			cout << endl;
	}
	return 0;
}
