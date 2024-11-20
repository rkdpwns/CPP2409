#include <iostream>
#include <string>
using namespace std;

class Car {
protected: // 여길 주석처리하면? private 처리됨
    int speed; // 속도
public:
    void SetSpeed(int s) { speed = s; }
    int GetSpeed() { return speed; }
};

class SportsCar : public Car {
    bool turbo;

public:
    void SetTurbo(bool newValue) { turbo = newValue; }
    bool GetTurbo() { return turbo; }
    void Print() {cout << "속도: " << speed << ", 터보: " << turbo << endl;}
};

int main()
{
    SportsCar c;
    
    c.SetSpeed(60); // 부모 클래스 함수 호출
    c.Print();
    c.SetTurbo(true); // 자식 클래스 함수 호출
    c.Print();
    c.SetSpeed(100);
    c.Print();
    c.SetTurbo(false);
    c.Print(); return 0;
}