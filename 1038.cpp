#include <iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N;
	int s[N];
	for(int i=0; i<N; ++i) cin >> s[i];
	cin >> K;
	int a[101] = {0},
		c[K];
	for(int i=0; i<K; ++i) cin >> c[i];
	for(int i=0; i<N; ++i)
		for(int j=0; j<K; ++j)
			if(s[i] == c[j]) {
				++a[c[j]];
				break;
			}
	cout << a[c[0]];
	for(int i=1; i<K; ++i) cout << " " << a[c[i]];
	return 0;
}
