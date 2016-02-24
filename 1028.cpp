#include <iostream>
#include <stdio.h>
using namespace std;

struct people {
	string name;
	int BirthYear,
		BirthMonth,
		BirthDay;
};

int Younger( const people * p1, const people * p2) {
	int res = -1;
	if( p1->BirthYear > p2->BirthYear)
		res = 1;
	else if( p1->BirthYear == p2->BirthYear)
		if( p1->BirthMonth > p2->BirthMonth)
			res = 1;
		else if( p1->BirthMonth == p2->BirthMonth)
			if( p1->BirthDay > p2->BirthDay)
				res = 1;
			else if( p1->BirthDay == p2->BirthDay)
				res = 0;
	return res;
}

bool isRight( const people * p) {
	int res = 0;
	people p1 = {"asd",2014,9,6},
		   p2 = {"adf",1814,9,6};
	if( Younger( p, &p1) == 1 || Younger( p, &p2) == -1) res = 1;
	if( res) return false;
	else return true;
}

int main() {
	people * array;
	int n;
	cin >> n;
	array = new people[n];
	for( int i = 0; i < n; ++i) {
		cin >> array[i].name;
		scanf("%d/%d/%d", &array[i].BirthYear, &array[i].BirthMonth, &array[i].BirthDay);
	}
	int right = 0, flag = 1;
	people old, young;
	for( int i = 0; i < n; ++i) {
		if( isRight( &array[i])) {
			if( flag ) {
				old   = array[i];
				young = array[i];
				flag  = 0;
			}
		 ++right;
		if( Younger( &young, &array[i]) == -1)  young = array[i];
		if( Younger( &old  , &array[i]) ==  1)  old   = array[i];
		}
		
	}
	cout << right;
	if( right) cout << " " << old.name << " " << young.name;
	delete []array;
	return 0;
}
