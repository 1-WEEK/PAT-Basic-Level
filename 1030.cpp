#include <iostream>
#include <stdlib.h>
using namespace std;

int Compare( const void * a, const void * b) {
    return *(int*)a - *(int*)b;
}

int main () {
    int n, p;
    cin >> n >> p;
    int a[n];
    for( int i=0; i<n; ++i) cin >> a[i];
    qsort( a, n, sizeof(int), Compare);
    int max = 0 ;
    for( int i = 0 ; i < n - max ; ++i ){
        while( (i + max < n) && ((long long)a[i+max] <= (long long)a[i]*p) )
            ++max;
    }
    cout << max;
    return 0;
}
