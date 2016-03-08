#include <iostream>
using namespace std;

int main() {
    string word[41] = {""};
    int i = 0, j;
    do {
        cin >> word[i];
        ++i;
    } while( i < 41 && cin.get() != '\n' );
    for ( j = i-1; j > 0; --j ) cout << word[j] << " ";
    cout << word[0];
    return 0;
}
