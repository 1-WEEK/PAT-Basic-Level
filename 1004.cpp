#include<iostream>
using namespace std;

struct student {
    string name, id;
    int grade;
};

int main() {
	int n;
    cin >> n;
    student s[n];
    for( int i=0; i<n; i++ ) cin >> s[i].name >> s[i].id >> s[i].grade;

    int max = 0, min = 0;
    for( int i=1; i<n; i++) {
        if( s[max].grade<s[i].grade ) max = i;
        if( s[min].grade>s[i].grade ) min = i;
    }

    cout << s[max].name << " " << s[max].id << endl;
    cout << s[min].name << " " << s[min].id << endl;
    return 0;
}
