#include <iostream>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int i(0), max(0), maxi(0);
    int Nums[100000] = {0};
    int n;
    for (; i<N; ++i) {
        scanf("%d",&n);
        if (n > max) {// ������������ֵ�� һ�����Խ���
            Nums[maxi++] = n;
            max = n;
        }
        else {// ���ܳ�Ϊ��Ԫ ��ȴ������̭������Ԫ
            int j = 0;
            for (j=maxi-1; j>=0; --j) {
                if (Nums[j] > n) {
                    Nums[j] = 0;
                    maxi--;
                }
                else {
                    maxi = j+1;
                    break;
                }
            }
        }
    }
    cout << maxi << endl;
    if (maxi)
        for (i=0; i<maxi; ++i) {
            if(!i) cout << Nums[i];
            else cout << " " << Nums[i];
        }
    cout << endl;
    return 0;
}
