#include<iostream>
using namespace std;

int main() {
    string word[41] = {""};
    int i = 0;
    while( i < 41) {
        cin >> word[i];
        ++i;
        if( cin.get() == '\n' ) break; 
    }
    for ( int j = i-1; j > 0; --j) cout << word[j] << " ";
    cout << word[0];
    return 0;
}
