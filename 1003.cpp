#include<iostream>
using namespace std;

void runTime( int n );
int sayYes( char ca[] );
void print( int n );

int main() {
    int n;
    cin >> n;
    runTime( n );
    return 0;
}

void runTime( int n ) {
    char ca[n][100] = {};
    for( int i=0; i<n; i++ ) {
        cin >> ca[i];
    }
    for( int i=0; i<n; i++ ) {
        print( sayYes( ca[i] ) );
        cout << endl;
    }
}

int sayYes( char ca[] ) {
    int flagP = -1,
        flagT = -1,
        isYes =  1, i;

    for( i=0; i<100 && ca[i]!='\0'; i++) {
//        规则一 与 二 判断
        if( ca[i]!='P' && ca[i]!='A' && ca[i]!='T' ) return 0;
        else {
            if( ca[i]=='P' ) {
                if( flagP != -1 ) return 0;
                flagP = i;
            }
            else if( ca[i]=='T' ) {
                if( flagT != -1 ) return 0;
                flagT = i;
            }
        }
    }
    int a = flagP,
        b = flagT - flagP - 2,
        c = i - flagT - a -1;
    if( a<0 || b<0 || c<0 ) return 0;
//    按照规则三还原字符串
    if( b > 0 ) {
        char temp[100] = {};
        for(int j=0; j<a; j++ ) {
            temp[j] = 'A';
        }
        temp[flagP]   = 'P';
        for(int j=0; j<b; j++ ) {
            temp[j+flagP+1] = 'A';
        }
        temp[flagT-1] = 'T';
        for(int j=0; j<c; j++ ) {
            temp[j+flagT] = 'A';
        }
//        递归
        isYes = sayYes(temp);
    }

    return isYes;
}

void print( int n ) {
    if( n == 1 ) cout << "YES";
    else cout << "NO";
}
