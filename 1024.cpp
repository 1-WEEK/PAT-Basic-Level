#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int num = 0, e;
    int len = s.length();
    for( int i=4; i<len; ++i)
        if( s[i] == 'E') e = i;

    for( int i=len-1, temp = 1; i>e+1; --i) {
        num += ( s[i] -'0')* temp;
        temp *= 10;
    }
    if( s[0] == '-') cout << '-';
    if( s[e+1] == '-') {
        cout << "0.";
        for( int i=0; i< num-1; ++i) cout << '0';
        cout << s[1];
        for( int i=3; i< e; ++i) cout << s[i];
    }

    else if( s[e+1] == '+'){
        int flag0 = 0;
        for( int i=3; i< e; ++i)
        	if( s[i] !='0') flag0 = 1;

		int flag = 0; // 无效位数的 "0"

        if( num >= (e-3)) { // 注意 "="
            if( s[1] != '0' || flag0 == 0) cout << s[1];
			for( int i=3; i< e; ++i) {
                if( s[i] != '0' || flag == 1) {
                    cout << s[i];
                    flag = 1;
                }
                else if( !flag0)
                	cout << s[i];
        	}
            for( int i=0; i< (num-e+3); ++i) cout << '0';
        }
        else {
        	cout << s[1];
            for( int i=3; i< 3+num; ++i) {
                if( s[i] != '0' || flag == 1) {
                    cout << s[i];
                    flag = 1;
                    }
        	}
            cout << '.';
            for( int i=3+num; i< e; ++i)   cout << s[i];
        }
    }
    return 0;
}
