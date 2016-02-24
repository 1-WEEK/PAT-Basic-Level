#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int IDTYPE = 8;

class student {
private:
    int c, d, sum, id, group;
public:
    void init( int, int, int, int, int);
    void print();
    int getD()     { return d;}
    int getSum()   { return sum;}
    int getId()    { return id;}
    int getGroup() { return group;}
};

void swap  ( int *, int *);
int  gCount( int, student *, int);
void sortPrint( int, student *, int);
bool compare(student a,student b) //??a?b????true,??a?b??
{
    if(a.getSum()>b.getSum())
        return true;
    else if(a.getSum() == b.getSum())
    {
        if(a.getD()>b.getD())
            return true;
        else if(a.getD()==b.getD())
        {
            if(a.getId()<b.getId())
                return true;
        }
    }
    return false;
}

int main() {
    int tempC, tempD, tempId, n, l, h;
    cin >> n >> l >> h;
    student s[n], * ps;
    ps = s;
    for( int i = 0; i < n; ++i) {
        cin >> tempId >> tempD >> tempC;
        s[i].init( tempId, tempD, tempC, l, h);
    }
    cout << n - gCount( 0, ps, n) << endl;
    for( int i = 1; i < 5; ++i)
        sortPrint(i, ps, n);
    return 0;
}

void student::init( int Id, int dsore, int csore, int l, int h) {
    this->id = Id;
    this->d  = dsore;
    this->c  = csore;
    this->sum = d + c;
    if( d>=l && c>=l) {
        if( c>=h && d>=h) this->group = 1;
        else if( d >= h)  this->group = 2;
        else if( d >= c)  this->group = 3;
        else              this->group = 4;
    }
    else this->group = 0;
}
void student::print() {
    cout << id << " " << d << " " << c << endl;
}

int gCount( int g, student * s, int n) {
    int count = 0;
    for( int i = 0; i < n; ++i)
        if( s[i].getGroup() == g) ++count;
    return count;
}

void swap( int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortPrint( int g, student * s, int n) {
    int count = gCount( g, s, n);
    int a[count], t = 0;
    for( int i = 0; i < n; ++i) {
        if( s[i].getGroup() == g) a[t++] = i;
    }

    sort(s[a[0]],s[a[count]],compare);

    for( int i = 0; i < count; ++i)
        s[a[i]].print();
}
