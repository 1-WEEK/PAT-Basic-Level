#include <iostream>
#include <stdio.h>
using namespace std;
int count[128];

int main() {
	char c;
	while ((c=getchar()) != '\n') {
		++count[c];
	}
	int max = 0, i;
	for (i='A'; i<='Z'; ++i)
		count[i-'A'+'a'] += count[i];
	for (i='a'; i<='z'; ++i) {
		if (count[max] < count[i]) max = i;
	}
	cout << (char)max << " " << count[max];
//	printf("%c %d", max, count[max]);
	return 0;
}
