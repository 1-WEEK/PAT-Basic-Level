#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct peo{
    int height;
    string name;
};

bool Comp(peo p1, peo p2) {
    if (p1.height != p2.height) return p1.height > p2.height;
    else return p1.name < p2.name;
}

int main()
{
    int N, K, i, j;
    cin >> N >> K;
    if (K) {
        peo p[N];
        for (i=0; i<N; ++i) {
            cin >> p[i].name;
            scanf("%d" ,&p[i].height);
        }
        sort(p, p+N, Comp);
        int m = N/K + N%K, t = 0, k;
        string list[K][m];
        for (i=0; i<K; ++i) {
            if (i) m = N/K;
            k=1;
            for (j=1; j<=m; ++j) {
                list[i][m/2+j/2*k] = p[t++].name;
                k*=-1;
            }
            for (j=0; j<m; ++j) {
                if (j) printf(" ");
                cout << list[i][j];
            }
            printf("\n");
        }
    }
    return 0;
}
