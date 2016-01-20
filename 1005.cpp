#include<iostream>
using namespace std;

int  fun1( int num );
bool fun2( int num );
void print( int * p, int n);
void fun3( int num, int * p );
void PopSort( int * p, int n );
bool judge( int num, int * p, int count );

class cNum {
	private:
		int  num, count, *p, array[100];
		bool cover;
	public:
		cNum();
		int  getNum();
		int  getCount();
		int * getP();
		void setP( int * point );
		bool isCover();
		void setNum( int n );
		void setCount( int n );
		void setCover( bool b );
};

int main() {
//	输入 
	int n, coun = 0;
	cin >> n;
	cNum cn[n];
	int a[n];
	for( int i=0; i<n; i++ ) {
		int temp; 
		cin >> temp;
		cn[i].setNum( temp );
		cn[i].setCount( fun1(temp) );
	}
	
//	覆盖的数组 
	for( int i=0; i<n; i++ ) {
		fun3( cn[i].getNum(), cn[i].getP() );
	}
	
	for( int i=0; i<n; i++) {
		for( int j=0; j<n; j++ ) {
			if(i==j) continue;
			if(cn[i].isCover()) break;
			cn[i].setCover( judge( cn[i].getNum(), cn[j].getP(), cn[j].getCount() ) );
		}
	}
	for( int i=0; i<n; i++ ) {
		if(!cn[i].isCover()) a[coun++] = cn[i].getNum();
	}
	PopSort( a, coun );
	print( a, coun );
	return 0;
}
cNum::cNum() {
	this->p = this->array;
	this->cover = false;
}
void cNum::setP( int * point ) {
	this->p = point;
}
void cNum::setCount( int n ) {
	this->count = n;
}
void cNum::setCover( bool b ) {
	this->cover = b;
}
void cNum::setNum( int n ) {
	this->num = n;
}
int * cNum::getP() {
	return this->p;
}
int cNum::getNum() {
	return this->num;
}
int cNum::getCount() {
	return this->count;
}
bool cNum::isCover() {
	return this->cover;
}
void print( int * p, int n ) {
	for( int i=0; i<n-1; i++ ) cout << p[i] << " ";
	cout << p[n-1];
}
void PopSort( int * p, int n ) {
	int temp = p[0];
	for( int i=0; i<n-1; i++ ) {
		for( int j=0; j<n-i-1; j++ ) {
			if( p[j]<p[j+1]) {
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
}
//	判断奇数偶数 
bool fun2(int num) {
    if( num%2==0 ) return true;
    else return false;
}

int fun1(int num) {
    if(num > 1000) return 0;
    int cout = 0;
    while( num != 1 ) {
        if(fun2(num)) num = num/2;
        else num = (3*num+1)/2;
        cout ++;
    }
    return cout;
} 	

bool judge( int num, int *p, int count ) {
	for(int i=0; i<count; i++ ) {
		if( num==*(p+i) ) return true;
	}
	return false; 
}

void fun3( int num, int * p ) {
	int i = 0;
	while( num != 1 ) {
        if( fun2(num) ) {
			num = num/2;
			*(p+i++) = num;
		}
        else {
        	num = (3*num+1)/2;
        	*(p+i++) = num;
        } 
    }
}
