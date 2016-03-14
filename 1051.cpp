#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    double r1, p1, r2, p2, a1, b1, a2, b2;
    cin >> r1 >> p1 >> r2 >> p2;
    a1 = r1*cos(p1), b1 = r1*sin(p1);
    a2 = r2*cos(p2), b2 = r2*sin(p2);
    double a, b;
    a = a1*a2 - b1*b2;
    b = a1*b2 + a2*b1;
    if (a + 0.01 >= 0 && a < 0)
        printf("0.00");
    else
        printf("%.2f", a);
    if(b >= 0)
        printf("+%.2fi", b);
    else if (b + 0.01 >= 0 && b < 0)
        printf("+0.00i");
    else
        printf("%.2fi", b);
    return 0;
}
