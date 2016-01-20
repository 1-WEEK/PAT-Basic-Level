#include<iostream>
using namespace std;

void run();

class student {
    private:
        string name, id;
        int grade;
    public:
        void printAll();
        void init();
        int getGrade();
};

int main() {
    run();
    return 0;
}

void run() {
    int n;
    cin >> n;
    student s[n];
    for( int i=0; i<n; i++ ) s[i].init();
    
    int max = 0, min = 0;
    for( int i=1; i<n; i++) {
        if( s[max].getGrade()<s[i].getGrade() ) max = i;
        if( s[min].getGrade()>s[i].getGrade() ) min = i;
    }
    
    s[max].printAll();
    s[min].printAll();
}

int student::getGrade() {
    return this->grade;
}
void student::printAll() {
    cout << this->name << " " << this->id << endl;
}
void student::init() {
    cin >> this->name >> this->id >> this->grade;
}
