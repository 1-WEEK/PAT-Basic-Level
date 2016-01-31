#include <iostream>
#include <iomanip>
using namespace std;

struct Yue{
	float inventory;
	float price;
};

int main() {
	int n;
	cin >> n;
	Yue a[n];
	float inventorySum, priceSum = 0.0;
	cin >> inventorySum;
	for( int i=0; i<n; ++i) cin >> a[i].inventory;
	for( int i=0; i<n; ++i) {
		float temp;
		cin >> temp;
		a[i].price = temp / a[i].inventory;
	}
	for( int i=0; i<n-1; ++i)
		for( int j=0; j<n-1-i; ++j)
			if( a[j].price < a[j+1].price) {
				Yue temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
	for( int i=0; i<n || !inventorySum; ++i) {
		if( a[i].inventory < inventorySum) {
			priceSum += a[i].inventory * a[i].price;
			inventorySum -= a[i].inventory;
		}
		else {
			priceSum += inventorySum*a[i].price;
			break;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << priceSum;
	return 0;
}
