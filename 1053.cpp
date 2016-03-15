#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int N, D, i, maybe(0), be(0);
    double e;
    cin >> N >> e >> D;
    for (i = 0; i < N; ++i) {
        int day, tempday(0);
        double valu;
        scanf("%d", &day);
        for (int j=0; j<day; ++j) {
            scanf("%lf", &valu);
            if (valu<e) tempday++;
        }
        if( tempday>day/2 ) maybe++;
        if( day>D && tempday>day/2 ) {
            maybe--;
            be++;
        }
    }
    printf("%.1lf", (double)maybe/(double)N*100.00);
    cout << "% ";
    printf("%.1lf", (double)be/(double)N*100.00);
    cout << "%" << endl;
    return 0;
}
