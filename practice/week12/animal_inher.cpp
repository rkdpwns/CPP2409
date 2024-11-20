#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    void Speak()
    {
        cout << "동물이 소리를 내고 있음" << endl;
    }
};
class Dog : public Animal {
public:

    void Speak() // 이 함수를 주석처리 하면?
    {
        cout << "멍멍!" << endl;
    }
};

int main()
{
    Dog obj;
    obj.Speak();
    return 0;
}