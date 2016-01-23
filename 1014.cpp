#include<iostream>
#include<iomanip>
using namespace std;

bool isCap( const char * c) {
	if( c[0] >= 'A' && c[0] <= 'G') return true;
	return false;
}
bool isChar( const char * c) {
	if(( c[0] >= 'a' && c[0] <= 'z' ) || ( c[0] >= 'A' && c[0] <= 'Z' )) return true;
	return false;
}
bool isH( const char * c) {
	if(( c[0] >= 'A' && c[0] <= 'N' )) return true;
	return false;
}
bool isNum( const char * c) {
	if( c[0] >= '0' && c[0] <= '9') return true;
	return false;
}
void printT( int d, int h, int m) {
	switch (d) {
        case 1: cout << "MON ";break;
        case 2: cout << "TUE ";break;
        case 3: cout << "WED ";break;
        case 4: cout << "THU ";break;
        case 5: cout << "FRI ";break;
        case 6: cout << "SAT ";break;
        case 7: cout << "SUN ";break;
    }
	cout << setfill('0') << setw(2) << h << ":";
	cout << setfill('0') << setw(2) << m;
}

int main() {
	int min, day, h = 0, m, count, tag;
	string s[4];
	cin >> s[0] >> s[1] >> s[2] >> s[3];
	min =( s[0].length() < s[1].length(), s[1].length(), s[0].length() );
//	cout << min << endl;
//	DAY
	for( int i = 0; i < min; ++i)
		if( s[0].substr(i, 1) == s[1].substr(i, 1) ) {
			if( isCap( s[0].substr(i, 1).c_str())) {
				day = *s[0].substr(i, 1).c_str() - 'A' + 1; // ¿ÉÄÜÅÐ¶Ï
				tag = i;
				break;
			}
		}

//	HH
	for( int i = tag+1; i < min; ++i) {
		if( s[0].substr(i, 1) == s[1].substr(i, 1) ) {
			if( isH( s[0].substr(i, 1).c_str()) || isNum( s[0].substr(i, 1).c_str())) {
				if( isH( s[0].substr(i, 1).c_str())) h = *s[0].substr(i, 1).c_str() - 'A' + 10;
				if( isNum( s[0].substr(i, 1).c_str())) h = *s[0].substr(i, 1).c_str() - '0';
				break;
			}
		}
	}

//	MM
	min =( s[2].length() < s[3].length(), s[3].length(), s[2].length() );
	for( int i = 0; i < min; ++i)
		if( s[2].substr(i, 1) == s[3].substr(i, 1) && ( isChar( s[2].substr(i, 1).c_str()))) { m = i;
		break; }

	printT( day, h, m);
	return 0;
}

//char
/*
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

bool funDay( const char c) {
    if( c >= 'A' && c <= 'G') return true;
    return false;
}
bool funMM( const char c) {
    if(( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' )) return true;
    return false;
}
bool funC( const char c) {
    if(( c >= 'A' && c <= 'N' )) return true;
    return false;
}
bool funN( const char c) {
    if( c >= '0' && c <= '9') return true;
    return false;
}
void printT( int d, int h, int m) {
    switch (d) {
        case 1: cout << "MON ";break;
        case 2: cout << "TUE ";break;
        case 3: cout << "WED ";break;
        case 4: cout << "THU ";break;
        case 5: cout << "FRI ";break;
        case 6: cout << "SAT ";break;
        case 7: cout << "SUN ";break;
    }
    cout << setfill('0') << setw(2) << h << ":";
    cout << setfill('0') << setw(2) << m;
}

int main() {
    int min, day, h, m, tag;
    char s[4][61];
    gets( s[0] );
    gets( s[1] );
    gets( s[2] );
    gets( s[3] );
    min =( strlen(s[0]) < strlen(s[1]), strlen(s[1]), strlen(s[0]) );
//  cout << min << endl;
//  DAY
    for( int i = 0; i < min; ++i)
        if( s[0][i] == s[1][i] && funDay( s[0][i]) ) {
                day = s[0][i] - 'A' + 1; // ?¨¦?¨¹?D??
                tag = i;
                break;
        }

//  HH
    for( int i = tag+1; i < min; ++i) {
        if( s[0][i] == s[1][i] ) {
            if( funC( s[0][i]) || funN( s[0][i])) {
                if( funC( s[0][i])) h = s[0][i] - 'A' + 10;
                if( funN( s[0][i])) h = s[0][i] - '0';
                break;
            }
        }
    }

//  MM
    min =( strlen(s[2]) < strlen(s[3]), strlen(s[3]), strlen(s[2]) );
    for( int i = 0; i < min; ++i)
        if( s[2][i] == s[3][i] && ( funMM( s[2][i]))) { m = i;break; }

    printT( day, h, m);
    return 0;
}
*/
