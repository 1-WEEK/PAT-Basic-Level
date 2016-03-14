#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

void input( vector<string> &s );
void print( int K[5], vector<string> &hands, vector<string> &eyes, vector<string> &mouth);

int main() {
    vector<string> hands, eyes, mouth;
    input( hands );
    input( eyes  );
    input( mouth );
    int n, i, j;
    cin >> n;
    int K[n][5];
    for( i=0; i<n; ++i )
        for( j=0; j<5; ++j )
            cin >> K[i][j];
    for( i=0; i<n; ++i )
        print( K[i], hands, eyes, mouth);
    return 0;
}

void input( vector<string> &s ) {
    string temps, str;
    int flag = 0, i(0);
    getline(cin, temps);
    while (i!=temps.length()) {
        if( temps[i] == '[' ) {
            flag = 1;i++;continue;
        }
        if( temps[i] == ']' && flag ) {
            flag = 0;
            s.push_back( str );
            str.clear();
            i++;
            continue;
        }
        if( flag )
            str += temps[i];
        ++i;
    }
}

void print( int K[5], vector<string> &hands, vector<string> &eyes, vector<string> &mouth) {
    int i, flag = 1;
    for (i = 0; i < 5; ++i)
        if (K[i] < 1) {
          flag = 0;
          break;
        }

    if (flag) {
        if (K[0] > hands.size() || K[4] > hands.size() || K[1] > eyes.size() || K[3] > eyes.size() || K[2] > mouth.size())
            flag = 0;
    }
    if (!flag)
        cout << "Are you kidding me? @\\/@" <<endl;
    else
        cout << hands[K[0]-1] << "(" << eyes[K[1]-1] << mouth[K[2]-1] << eyes[K[3]-1] << ")" << hands[K[4]-1] << endl;
}
