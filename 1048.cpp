#include <iostream>
using namespace std;

const string digit = "0123456789JQK";

int main()
{
    string numA, numB, num;
    cin >> numA;
    cin >> numB;
    int i, k = numA.length() - numB.length(), flag(1), temp(0);
    if(k>0) {
        for( i=0; i<k; ++i )
            numB = '0' + numB;
        k = numA.length() - numB.length();
    }
    for( i=numA.length()-1; i>=0; --i ) {
        if(flag>0) {
            num = digit[( ( numA[i] + numB[i-k] - '0'*2 )%13 )] + num;
        }
        else {
            temp = numB[i-k] - numA[i];
            if( temp<0) temp += 10;
            num = (char)(temp+'0') + num;
        }
        flag *= -1;
    }
    if(k<0) {
        for( i=-k-1; i>=0; --i )
            num = numB[i] + num;
    }
    cout << num << endl;
    return 0;
}
