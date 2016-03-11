#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    int N; cin >> N;
    int m, n, i, j, list[N];
    for( i=0; i<N; ++i )
        scanf("%d", &list[i]);
    sort(list, list+N);
//    found m & n
    for( i=sqrt(N); i>=1; --i ) {
        if(N%i == 0) {
            m = i;
            n = N/i;
            break;
        }
    }
    if( m<n ) {
        int temp = m;
        m = n;
        n = temp;
    }
//    level
    int matrix[m][n];
    for( i=0; i<(n+1)/2; ++i ) {
        for( j=i; j<n-i; ++j ) {
            if( N == 0 ) break;
            matrix[i][j] = list[--N];
        }
        for( j=i+1; j<m-i; ++j ) {
            if( N == 0 ) break;
            matrix[j][n-1-i] = list[--N];
        }
        for( j=n-2-i; j>=i; --j ) {
            if( N == 0 ) break;
            matrix[m-1-i][j] = list[--N];
        }
        for( j=m-2-i; j>i; --j ) {
            if( N == 0 ) break;
            matrix[j][i] = list[--N];
        }
        if( N == 0 ) break;
    }
//    print
    for( i=0; i<m; ++i ) {
        for( j=0; j<n; ++j ) {
            if(!j) printf("%d", matrix[i][j]);
            else printf(" %d", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
