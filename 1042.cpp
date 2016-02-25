#include <iostream>
using namespace std;

struct word{
	char c;
	int n;
};

int main() {
	char C;
	word x[26];
	for(int i=0; i<26; ++i) {
		x[i].c = (char)('a'+i);
		x[i].n = 0;
	}
	while((C = cin.get()) != EOF ) {
		if( C > 'A' && C < 'Z') C += 'a' - 'A';
		if( C > 'a' && C < 'z')
			for(int i=0; i<26; ++i)
				if( C == x[i].c) {
					++x[i].n;break;
				}
	}
	word max = x[0];
	for(int i=1; i<26; ++i) {
		if(max.n < x[i].n) max = x[i];
	}
	cout << max.c << " " << max.n;
	return 0;
}
