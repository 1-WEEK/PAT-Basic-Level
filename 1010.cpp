#include<iostream>
using namespace std;

int main() {
//  input
    int a[100];
    int n = 0;
 	for(;;) {
    	cin >> a[n++];
    	if( cin.get() == '\n') break;
 	}
 	if( a[1] != 0 && a[0] != 0) {
    	int a1[n];
	    for ( int i = 0; i < n; i += 2) {
	      	if( a[i+1] == 0 && a[i] != 0) {
	          	n = i;
	          	break;
	      	}
			a1[i] = a[i] * a[i+1];
	        if( a[i] == 0) a1[i+1] = 0;
			else a1[i+1] = a[i+1] - 1;
	    }
	    for( int i = 0; i < n - 1; i++) cout << a1[i] << " ";
	    cout << a1[n-1];
	}
	else cout << "0 0";
    return 0;
}
