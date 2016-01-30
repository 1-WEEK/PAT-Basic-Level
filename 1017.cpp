#include <iostream>
#include <string>
using namespace std;

int main() {
    string A;
    cin >> A;
    int B, R = 0, Q, flag = 0;
    cin >> B;
    int len = A.length();
    Q = ( A[0] - '0' )/ B;
    if ( (Q != 0 && len > 1) || len == 1)
        cout << Q;
    R = ( A[0] - '0' )% B;
    for( int i=1; i<len; ++i) {
        Q = ( R*10 + A[i] - '0' )/ B;
        R = ( R*10 + A[i] - '0' )% B;
        cout << Q;
    }
    cout << " " << R;
    return 0;
}
