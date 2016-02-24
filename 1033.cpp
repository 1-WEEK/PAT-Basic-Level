#include <iostream>
#include <ctype.h>
using namespace std;

bool isWoring( char rs, char wkey) {
	int flag = 1;
	if( isalpha( rs)) {
		if( isupper( rs) ){
			if( wkey == '+' || rs == wkey) flag = 0;
		}
		else {
			if( (char)( rs-32) == wkey ) flag = 0;
	 }
	}
	else if( rs == wkey) flag = 0;
	if( flag) return false;
	else return true;  
}

int main() {
	string wkey = "", rs;char a[100000];
	wkey = cin.get();
	if( wkey[0] != '\n') {
		string temp;
		cin >> temp;
		wkey += temp;
		cin >> rs;
		int flag1=0;
		for( int i=0; i<rs.length(); ++i) {
			int flag = 1;
			for( int j=0; j<wkey.length(); ++j)
				if( isWoring( rs[i], wkey[j]) ) {
					flag = 0;
					break;
				}
			if( flag ) cout << rs[i];
		}
	}
	else {
		cin >> rs;
		cout << rs;
	}
	return 0;
} 
