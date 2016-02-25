#include<iostream>
using namespace std;

struct Student{
	int testNum,
		examNum;
	string examId;
};

int main() {
	int n;
	cin >> n;
	Student s[n];
	for(int i=0; i<n; ++i) {
		cin >> s[i].examId;
		cin >> s[i].testNum >> s[i].examNum;
	}
	int m;
	cin >> m;
	int a[m];
	for(int i=0; i<m; ++i) cin >> a[i];
	for(int i=0; i<m; ++i) {
		for(int j=0; j<n; ++j)
			if(a[i] == s[j].testNum) cout << s[j].examId << " " << s[j].examNum << endl;
	}
	return 0;
} 
