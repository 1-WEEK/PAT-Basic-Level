#include <iostream>
#include <ctype.h>
#include <iomanip>
using namespace std;
const string week_day[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int main() {
    string text[4];
    int i, flag = 0;
    for( i=0; i<4; ++i ) cin >> text[i];
    for( i=0; i<text[1].length() && i<text[0].length(); ++i )
        if( text[0][i] == text[1][i] ) {
            if( (text[0][i] >= 'A' && text[0][i] <= 'G') && !flag) {
                cout << week_day[ text[0][i] - 'A' ] << " ";
                flag = 1;
            }
            else if( (isdigit(text[0][i]) || (text[0][i] >= 'A' && text[0][i] <= 'N')) && flag ) {
                if( isdigit(text[0][i]) ) {
                    cout << "0" << text[0][i] << ":";
                    break;
                }
                else {
                    cout << text[0][i] - 'A' + 10 << ":";
                    break;
                }
            }
        }
    for( i=0; i<text[2].length() && i<text[3].length(); ++i ) {
        if( text[2][i] == text[3][i] && isalpha(text[3][i]) ) {
            cout << setfill('0') << setw(2) << i << endl;
            break;
        }
    }
    return 0;
}
