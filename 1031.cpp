#include <iostream>
#include <ctype.h>
using namespace std;

const int weight[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
const char M[] = { '1','0','X','9','8','7','6','5','4','3','2' };

int main() {
	int n,flage1 = 0, flage2 = 0;
	cin >> n;
	string s[n];
	for( int i=0; i<n; ++i) cin >> s[i];
	for( int j=0; j<n; ++j) {
		int flage = 0, sum = 0;
		for( int i=0; i<17; ++i) {
			if( isdigit(s[j][i])) sum += weight[i] * ( s[j][i] - '0');
			else {
				flage = 1;
				flage1= 1;
				break;
			}
		}
		if( flage || M[sum%11] != s[j][17]) {
			flage = 1;
			flage1= 1;
		}
		if( flage && !flage2 ) {
			cout << s[j];
			flage2 = 1;
		}
		else if( flage ) cout << "\n" << s[j];
	}
	if( !flage1) cout <<"All passed";
	return 0;
}
