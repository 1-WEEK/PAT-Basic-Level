#include<iostream>
using namespace std;

class Man {
private:
	int win;
	int lose;
	int draw;
	int C, J, B;
public:
	Man(){
		win  = 0;
		lose = 0;
		draw = 0;
		C = 0;
		J = 0;
		B = 0;
	}
	void battle( char me, char he);
	void display();
	void Win( char t);
	char Max();
};

int main() {
	Man Jia, Yi;
	char tempj, tempy;
	int n;
	cin >> n;
	while(n--) {
		cin >> tempj >> tempy;
		Jia.battle( tempj, tempy);
		Yi .battle( tempy, tempj);
	}
	Jia.display();
	Yi .display();
	cout << Jia.Max() << " " << Yi.Max();
	return 0;
}

void Man:: battle( char me, char he) {
	int cwin = 'c' - 'j',
		jwin = 'j' - 'b',
		bwin = 'b' - 'c',
		res  = me  - he ;
	if( !res) ++draw;
	else if( res == jwin || res == -jwin) {
		if( res > 0) this->Win(me);
		else ++lose;
	}
	else if(res < 0) this->Win(me);
	else ++lose;
}
void Man:: display() {
	cout << win << " " << draw << " " << lose << endl;
}
char Man:: Max() {
//	cout <<"C:"<< C << ", B:" << B  << ", J:" << J << endl;
	char t = 'B';
	if( B < J) {
		t = 'J';
		if( J <= C)
			t = 'C';
	}
	else if( B < C) {
		t = 'C';
		if( C < J)
			t = 'J';
	}
    switch (t) {
        case 'C': {
            return 'C';
            break;
        }
        case 'J': {
            return 'J';
            break;
        }
        case 'B': {
            return 'B';
            break;
        }
    }
}
void Man::Win( char t) {
	++win;
//	cout << "--";
	switch (t) {
		case 'C': {
			++C;
//			cout << "--C" <<  C << endl;
			break;
		}
		case 'J': {
			++J;
//			cout << "--J" << J << endl;
			break;
		}
		case 'B': {
			++B;
//			cout << "--B" << B << endl;
			break;
		}
	}
} 
