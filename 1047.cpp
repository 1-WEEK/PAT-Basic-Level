#include <iostream>
#include <cstdio>
using namespace std;

int fenshu[1001];

int main()
{
    int n, max(0), maxt;
    cin >> n;
    int team, fen;
    while(n--) {
        scanf("%d-%d %d", &team, &fen, &fen);
        fenshu[team] += fen;
        if( fenshu[team] > max ) {
            max = fenshu[team];
            maxt = team;
        }
    }
    cout << maxt << " " << max;
    return 0;
}
