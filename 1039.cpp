#include <iostream>
using namespace std;

int main() {
	string sale, want;
	int count = 0;
	cin >> sale;
	cin >> want;
	for(int i=0; i<want.length(); ++i)
		for(int j=0; j<sale.length(); ++j)
			if(sale[j] == want[i]) {
				++count;
				sale[j] = ' ';
				break;
			}
	if(count == want.length())
		cout << "Yes " << sale.length() - want.length();
	else
		cout << "No " << want.length() - count;
	return 0;
}

