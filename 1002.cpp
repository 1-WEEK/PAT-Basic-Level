#include<iostream>
using namespace std;

const string pinyin[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int val[100];

int main() {
    char c;
    int num(0), count(0);
    while ((c=getchar())!='\n') {
    	num += c - '0';
	}
	if (!num) {
		cout << pinyin[0];
    }
    else {
        while (num) {
            val[count++] = num % 10;
            num /= 10;
        }
        while (count--) {
        	cout << pinyin[val[count]];
            if (count)
                putchar(' ');
        }
    }
    return 0;
}
