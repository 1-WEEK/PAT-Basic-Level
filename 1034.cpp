#include <iostream>
#include <stdio.h>
using namespace std;

struct fraction {
	long long numerator;
	long long denominator;
};

long long GCD( long long a, long long b) { // 最大公约数 
	long long m = a % b;
	while( m ) {
		a = b;
		b = m;
		m = a % b;
	}
	return b;
}

void printFraction(long long n, long long d) {
	long long k = 1;
	if(d == 0) {
		cout << "Inf";
		return;
	}
	if(n < 0) { //
		n = -n;
		k = -1;
	}
	long long gcd = GCD(n, d); 
	n /= gcd; // 简化 
	d /= gcd;
	if(n / d == 0 && n != 0) { // 真分数输出 
		if(k > 0)
			cout << n << "/" << d;
		else
			cout << "(-" << n << "/" << d << ")";
		return;
	}
	k = k * n / d; //	假分数输出 
	n %= d;
	if(d == 1 && k < 0) 
		cout << "(" << k << ")";
	else if(d == 1 && k >= 0)
		cout << k;
	else if(k < 0)
		cout << "(" << k << " " << n << "/" << d << ")";
	else
		cout << k << " " << n << "/" << d;
}

void Print(long long n1, long long d1, long long n2, long long d2, char ch) {
	long long c1, c2;
	printFraction(n1, d1);
	printf(" %c ", ch);
	printFraction(n2, d2);
	cout << " = ";
	switch(ch) {
		case '+':
			c1 = n1 * d2 + n2 * d1;
			c2 = d1 * d2;
			printFraction(c1, c2);
			cout << endl;
			break;
		case '-':
			c1 = n1 * d2 - n2 * d1;
			c2 = d1 * d2;
			printFraction(c1, c2);
			cout << endl;
			break;
		case '*':
			c1 = n1 * n2;
			c2 = d1 * d2;
			printFraction(c1, c2);
			cout << endl;
			break;
		case '/': // 只有分子可以是负数，若分母为负，转为分子 
			c1 = n1 * d2;
			c2 = d1 * n2;
			if(c2 < 0) {
				c2 = -c2;
				c1 = -c1;
			}
			printFraction(c1, c2);
			cout << endl;
			break;
	}
}

int main() {
	fraction a, b;
	scanf("%lld/%lld  %lld/%lld", &a.numerator, &a.denominator, &b.numerator, &b.denominator);
	Print(a.numerator, a.denominator, b.numerator, b.denominator, '+');
	Print(a.numerator, a.denominator, b.numerator, b.denominator, '-');
	Print(a.numerator, a.denominator, b.numerator, b.denominator, '*');
	Print(a.numerator, a.denominator, b.numerator, b.denominator, '/');
	
	return 0;
}
