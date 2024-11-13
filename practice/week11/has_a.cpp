#include <iostream>
#include <string>

using namespace std;

class Date {
    int year, month, day;
public:
    Date() : year(0), month(0), day(0) {}  // 기본 생성자 추가
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    void Print() {
        cout << year << "." << month << "." << day << endl;
    }
};

class Person {
    string name;
    Date birth;
public:
    Person(string n, Date d) : name(n), birth(d) {}  // 초기화 리스트 사용
    void Print() {
        cout << name << ":";
        birth.Print();
        cout << endl;
    }
};


int main()
{
    Date d{ 1998, 3, 1 };
    Person p{ "김철수", d };
    p.Print();
    return 0;
}
