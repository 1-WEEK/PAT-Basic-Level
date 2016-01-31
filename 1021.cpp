#include <iostream>
using namespace std;

struct D{
	char a;
	int c;
};

int main() {
	string N;
	cin >> N;
	int len = N.length();
	D array[10];
	for( int i=0; i<10; ++i) {
		array[i].a = '0'+i;
		array[i].c = 0;
	}
	for( int i=0; i<len; ++i)
		for( int j=0; j<10; ++j)
			if( N[i] == array[j].a) ++array[j].c;
	for( int i=0; i<10; ++i)
		if( array[i].c) cout << array[i].a << ":" << array[i].c << endl;
	return 0;
}
