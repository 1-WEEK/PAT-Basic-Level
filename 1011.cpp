#include<iostream>
using namespace std;

int main() {
	long n, a, b, c;
	cin >> n;
	string result[n];
	for(int i = 0; i < n; ++i) {
		cin >> a >> b >> c;
		if(( a + b )> c) result[i] = "true";
		else result[i] = "false";
	}
	for(int i = 1; i <= n; ++i) cout << "Case #" << i << ": " << result[i-1] << endl;
	return 0;
}
