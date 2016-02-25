#include <iostream>
using namespace std;

struct word{
	int n;
	char c;
};

int main() {
	word w[6];
	w[0].c = 'P', w[1].c = 'A', w[2].c = 'T';
	w[3].c = 'e', w[4].c = 's', w[5].c = 't';
	for(int i=0; i<6; ++i) w[i].n = 0;
	char C;
	while((C = getchar()) != EOF && C != '\n') {
		for(int i=0; i<6; ++i)
			if(w[i].c == C) {
				++w[i].n;
				break;
			}
	}
	while( w[0].n || w[1].n || w[2].n || w[3].n || w[4].n || w[5].n ) {
		for(int i=0; i<6; ++i)
			if(w[i].n) {
			cout << w[i].c;
			--w[i].n;
			}
	}
	return 0;
}
