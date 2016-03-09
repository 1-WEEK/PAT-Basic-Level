#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
struct student {
    int kaohao;
    int defen;
    int caifen;
    int zongfen;
};
bool compare(student a,student b) { //比较a在b前则返回true,表示a在b前面
    if(a.zongfen>b.zongfen)
        return true;
    else if(a.zongfen == b.zongfen) {
        if(a.defen>b.defen)
            return true;
        else if(a.defen==b.defen) {
            if(a.kaohao<b.kaohao)
                return true;
        }
    }
    return false;
}
int main() {
    vector<student> v1,v2,v3,v4;//表示四类考生
    student stu;//学生信息临时保存
    int count=0;//达标的学生总数
    int N,L,H;
    //cin>>N>>L>>H;
    scanf("%d %d %d",&N,&L,&H);
    int K,D,C;
    while(N--) {
        //cin>>K>>D>>C;
        scanf("%d%d%d",&K,&D,&C);
        stu.kaohao = K;
        stu.defen = D;
        stu.caifen = C;
        stu.zongfen = D+C;
        if(D>=L && C>=L) {
            count++;
            if(D>=H && C>=H)
                v1.push_back(stu);
            else if(D>=H && C<H )
                v2.push_back(stu);
            else if(D<H && C<H  && D>=C)
                v3.push_back(stu);
            else
                v4.push_back(stu);
        }
    }
    printf("%d\n",count);
    sort(v1.begin(),v1.end(),compare);
    sort(v2.begin(),v2.end(),compare);
    sort(v3.begin(),v3.end(),compare);
    sort(v4.begin(),v4.end(),compare);
    vector<student>::iterator itr;
    for(itr=v1.begin();itr!=v1.end();itr++)
        printf("%d %d %d\n",itr->kaohao,itr->defen,itr->caifen);
    for(itr=v2.begin();itr!=v2.end();itr++)
        printf("%d %d %d\n",itr->kaohao,itr->defen,itr->caifen);
    for(itr=v3.begin();itr!=v3.end();itr++)
        printf("%d %d %d\n",itr->kaohao,itr->defen,itr->caifen);
    for(itr=v4.begin();itr!=v4.end();itr++)
        printf("%d %d %d\n",itr->kaohao,itr->defen,itr->caifen);
    system("pause");
    return 0;
}
