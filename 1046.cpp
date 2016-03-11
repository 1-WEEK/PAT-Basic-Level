#include <cstdio>
using namespace std;

int main()
{
    int n(0);
    scanf("%d", &n);
    int a1, a2, b1, b2, ca(0), cb(0);
    while(n--) {
        scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
        a2 = (a2 == b1+a1);
        b2 = (b2 == b1+a1);
        if(a2 && !(a2&&b2))
            cb++;
        if(b2 && !(a2&&b2))
            ca++;
    }
    printf("%d %d", ca, cb);
    return 0;
}
