#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
    int n, i, t;
    cin >> n;
    double list[n+1], sum(0.0), totalsum(0.0);
    for( i=1; i<=n; ++i ) {
        cin >> list[i];
        sum += list[i]*(double)i*(double)(n-i+1);
    }
    printf("%.2f\n", sum);
    return 0;
}
