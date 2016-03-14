#include <iostream>
#include <iomanip>
using namespace std;
// 定义节点，模拟内存创建链表
struct linkNode {
    int Data, Next;
} lNode[100000];
void printList( int address);
int  reverseList( int start, int end);
int  fun( int start, int k);
int main() {
    int start; // 起始地址
    int n, k;  // n 节点数，k
    scanf("%d %d %d", &start, &n, &k);
    for( int i = 0; i < n; ++i) {
            int tempAddress;
            scanf("%d", &tempAddress);
            scanf("%d %d", &lNode[tempAddress].Data, &lNode[tempAddress].Next);
    }
    if( start == -1) {
        printf("-1");
    }
    else {
        if( k > 1){
            start = fun( start, k);
        }
        printList( start);
    }
    return 0;
}
// 遍历打印链表
void printList( int address) {
    cout << setfill('0') << setw(5) << address << " "
         << lNode[address].Data << " ";
    if( lNode[address].Next != -1)
        cout << setfill('0') << setw(5) << lNode[address].Next << endl;
    else {
        cout << -1 << endl;
        return;
    }
    printList( lNode[address].Next);
}
// 给定链表的开头及结尾指向，将其翻转
int reverseList( int start, int end) {
    if( lNode[start].Next == end) return start;
    int last = start;
    for(;;) {
        if( lNode[last].Next == end) break;
        last = lNode[last].Next;
    }
    int temp = lNode[start].Next;
    lNode[start].Next = end;
    lNode[last].Next = start;
    start = reverseList( temp, lNode[last].Next);
    return start;
}
int fun( int s, int k) {
    int i = 1, last = s;
    while( i%k != 0) {
        last = lNode[last].Next;
        ++i;
        if( last == -1) return s;
    }
    int end = lNode[last].Next;
    int start = reverseList( s, end);
    lNode[s].Next = fun( end, k);
    return start;
}
