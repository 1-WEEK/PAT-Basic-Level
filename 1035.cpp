#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int N;
    int A1[101], A2[101];  // ԭʼ����A1  �м�����A2
    int i, j;
    cin>>N;
    for (i=0; i<N; i++)    cin>>A1[i];
    for (i=0; i<N; i++)    cin>>A2[i];

    for (i=0; A2[i]<=A2[i+1] && i<N-1; i++) ; // i��Ϊ�����������һ��Ԫ���±��˳�ѭ��
    for (j=++i; A1[j]==A2[j] && j<N; j++ ) ;    // A1 A2�� ��һ�������Ԫ�ؿ�ʼ ��һ�ȶ�

    if (j==N) {// ǰ�벿���������벿��δ�Ķ�����ȷ���ǲ�������
        cout<<"Insertion Sort"<<endl;
        sort(A1, A1+i+1);
    }
    else {
        cout<<"Merge Sort"<<endl;
        int k = 1;1
        int flag=1;         //��������Ƿ�鲢�� ���м����С�
        while (flag)
        {
            flag = 0;
            for (i=0; i<N; i++)
                if (A1[i]!=A2[i])
                    flag = 1;
            k*=2;
            for (i=0; i<N/k; i++)
                sort(A1+i*k, A1+(i+1)*k);
            for (i=k*(N/k); i<N; i++) // �� ��ż�����еġ�β�͡���������
                sort(A1+k*(N/k), A1+N);
        }
    }
    cout<<A1[0];
    for (i=1; i<N; i++)
        cout<<" "<<A1[i];
    cout<<endl;

    return 0;
}
