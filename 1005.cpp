#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int k[101];


int main() {
//	input
	int n; cin >> n;
	int numList[n];
	for (int i=0; i<n; ++i)
		cin >> numList[i];
	int temp;
	for (int i=0; i<n; ++i) {
		if(!k[ numList[i] ]) {
			temp = numList[i];
			while (temp!= 1) {
				if (!(temp%2)){
		    		temp /= 2;
		    		k[temp] = 1;
				}
				else{
					temp = (3 * temp + 1)/ 2;
					k[temp] = 1;
				}
			}
		}
	}
	sort(numList, numList+n, greater<int>());
	int flag = 1;
	for (int i=0; i<n; ++i) {
		if(!k[numList[i]]) {
			if(flag) cout << numList[i] << " ";
			else cout << numList[i];
		}
	}
	cout << endl;
	return 0;
}
