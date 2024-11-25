#include <iostream>
using namespace std;

class RemoteControl {
public:
    virtual void TurnON() = 0;   // 가전제품을 켠다
    virtual void TurnOFF() = 0;  // 가전제품을 끈다
    virtual ~RemoteControl() {}  // 소멸자
};

class Television : public RemoteControl {
public:
    void TurnON() override {
        cout << "TV를 켭니다." << endl;
    }
    void TurnOFF() override {
        cout << "TV를 끕니다." << endl;
    }
};

class Refrigerator : public RemoteControl {
public:
    void TurnON() override {
        cout << "냉장고를 켭니다." << endl;
    }
    void TurnOFF() override {
        cout << "냉장고를 끕니다." << endl;
    }
};

int main() {
    RemoteControl* remoteTV = new Television();
    remoteTV->TurnON();
    remoteTV->TurnOFF();

    RemoteControl* remoteRefrigerator = new Refrigerator();
    remoteRefrigerator->TurnON();
    remoteRefrigerator->TurnOFF();
    
    delete remoteTV, remoteRefrigerator;

    return 0;
}
