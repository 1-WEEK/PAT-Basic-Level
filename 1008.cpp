#include<iostream>
using namespace std;

void move ( int * p, int n);
void print( int * p, int n);

int main() {
    int n, m;
    cin >> n >> m;
    int array[n], *p;
    p = array;
    for ( int i = 0; i < n; ++i) cin >> array[i];
    for ( int i = 0; i < m; ++i) move( p, n-1);
    print( p, n-1);
    return 0;
}

void move( int * p, int n) {
	int temp = p[n];
	for ( int i = n; i > 0; --i)
		p[i] = p[i-1];
	p[0] = temp;
}

void print( int * p, int n) {
    for (int i = 0; i < n; ++i)
        cout << p[i] << " ";
    cout << p[n];
}
