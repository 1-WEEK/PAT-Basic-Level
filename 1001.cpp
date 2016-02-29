#include<iostream>
using namespace std;

int main() {
    int num, count(0);
    cin >> num;
    while (num != 1) {
    	if (!(num%2))
    		num /= 2;
		else
			num = (3 * num + 1)/ 2;
		++count;
	}
	cout << count << endl;
    return 0;
} 
