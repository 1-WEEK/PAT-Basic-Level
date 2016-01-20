#include<iostream>
using namespace std;

int sum ( char c[] );
void print( int num );
void printByPin( int num );

int main() {
//    how to using string
    char c[100] = {};
    int s;
    cin >> c;
    s = sum( c );
    print( s );
    return 0;
}

int sum( char c[] ) {
    int nsum = 0;
    for( int i=0; i<100 && c[i]!= '\0'; i++ )
        nsum += c[i] - 48;
    return nsum;
}

void print( int num ) {
    int count = 0;
    int temp[1000] = {};
    while( num/10 > 0 ) {
        count++;
        temp[count] = num%10;
        num = ( num - temp[count] )/ 10;
    }
    printByPin( num );
    for(int i=count; i>0; i--) {
        cout<<" ";
        printByPin(temp[i]);
    }
}

void printByPin( int num ) {
    switch (num) {
        case 0:
            cout << "ling";break;
        case 1:
            cout << "yi";break;
        case 2:
            cout << "er";break;
        case 3:
            cout << "san";break;
        case 4:
            cout << "si";break;
        case 5:
            cout << "wu";break;
        case 6:
            cout << "liu";break;
        case 7:
            cout << "qi";break;
        case 8:
            cout << "ba";break;
        case 9:
            cout << "jiu";break;
    }
}
