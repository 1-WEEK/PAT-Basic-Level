#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctype.h>
using namespace std;

bool judge( string str) {
    int i, flag(1), flag1(1), jingdu(0);
    for (i=0; i<str.length(); ++i) {
        if (!isdigit(str[i])) {
            if( !i && str[i] == '-' )
                continue;
            else if( str[i] == '.' && flag ) {
                flag = 0;
                continue;
            }
            else
                return false;

        }
        else if( !flag )
            jingdu++;
    }
    double temp;
    stringstream(str) >> temp;
    if( jingdu>2 ) return false;
    if( temp>1000 || temp<-1000 ) return false;
    return true;
}

int main()
{
    int N, i, j, count(0), K;
    double sum;
    stringstream ss;
    cin >> N;
    string str[N];
    for (i=0; i<N; ++i) cin >> str[i];
    for (i=0; i<N; ++i) {
        if( judge(str[i]) ) {
            double temp;
            stringstream(str[i]) >> temp;
            sum += temp;
            ++count;
            K = i;
        }
        else
            cout << "ERROR: " << str[i] << " is not a legal number" << endl;
    }
    if (count > 1)
        printf("The average of %d numbers is %.2f", count,sum/(double)count);
    else if (count == 1)
        printf("The average of %d number is %.2f", count,sum/(double)count);
    else
        cout << "The average of 0 numbers is Undefined" << endl;
    return 0;
}
