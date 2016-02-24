#include <stdio.h>

int main(int argc, char *argv[]) {
    int rG = 0, rS = 0, rK = 0; 
    int sG = 0, sS = 0, sK = 0;
    int r,s,t;
    scanf("%d.%d.%d %d.%d.%d",&sG, &sS, &sK, &rG, &rS, &rK);
    r = rG * 493 + rS * 29 + rK ;
    s = sG * 493 + sS * 29 + sK ;
    t = r - s ; 
    if(t >= 0 ){
        printf("%d.%d.%d\n",t/493,t/29%17,t%29);
    }else{
        t = -t;
        printf("-%d.%d.%d\n",t/493,t/29%17,t%29);
    }
    return 0;
}
