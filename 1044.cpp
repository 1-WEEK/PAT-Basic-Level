#include <iostream>
#include <ctype.h>
using namespace std;

const string h[12] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
const string l[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
const string zero  = "tret";

void toMas(string number) {
	int num = 0;
	for (int i=0; i<number.length(); ++i) // string to int
		num = number[i] - '0' + num*10;
	int low  = num % 13;
	int high = num / 13;
	if (high) {
		cout << h[high - 1];
		if(low) cout << " ";
	}
	if (low)
		cout << l[low - 1];
	else if (!high)
		cout << zero;
	cout << endl;
}
int trans(string s) {
	int result = 0;
	for (int i=0; i<12; ++i) {
		if (s == h[i]) {
			result += (i + 1) * 13;
			break;
		}
		else if (s == l[i]) {
			result += 1 + i;
			break;
		}
		else if (s == zero) {
			result += 0;
			break;
		}
	}
	return result;
}
void toEarth(string number) {
	int result = 0;
	string s[2];
	int j = 0;
	for (int i=0; i<number.length(); ++i) {
		if (number[i] == ' ') {
			++j;continue;
		}
		s[j] += number[i];
	}
	for (int i=0; i<=j; ++i)
		result += trans(s[i]);
	cout << result << endl;
}

int main() {
	int n; cin >> n; cin.get(); //input
	string number[n];
	for (int i=0; i<n; ++i)
		getline(cin, number[i]);
	for (int i=0; i<n; ++i) {
		if (isdigit(number[i][0]))
			toMas(number[i]);
		else
			toEarth(number[i]);
	}
	return 0;
}
