#include <iostream>
#include <iomanip>
using namespace std;

void print( int n) {
	int h, m, s;
	s = n %  60;
	m = ( n /60 )% 60;
	h = n / 3600;
	cout << setfill('0') << setw(2) << h << ":"
		 << setfill('0') << setw(2) << m << ":"
		 << setfill('0') << setw(2) << s << endl;
}

int main() {
	int c1, c2;
	cin >> c1 >> c2;
	int s = c2 - c1;
	if( s % 100 >= 50) s = s / 100 + 1;
	else s /= 100;
	print( s );
	return 0;
}
