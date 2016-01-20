#include<iostream>
using namespace std;

bool fun2(int num) {
    if( num%2==0 ) return true;
    else return false;
}

int fun(int num) {
    if(num > 1000) return 0;
    int cout = 0;
    while( num != 1 ) {
        if(fun2(num)) num = num/2;
        else num = (3*num+1)/2;
        cout ++;
    }
    return cout;
}

int main() {
    int num1, num2;
    cin >> num1;
    num2 = fun( num1 );
    cout << num2 << endl;
    return 0;
} 
