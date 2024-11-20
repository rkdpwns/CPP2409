#include "user.h"

User::User() : hp(20), itemCnt(0) {}

void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
    if (hp < 0) hp = 0;
}

void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

int User::GetHP() const {
    return hp;
}

void User::AddItem() {
    itemCnt++;
}

int User::GetItemCnt() const {
    return itemCnt;
}

void User::doAttack() const {
    std::cout << "공격합니다!" << std::endl;
}

// 연산자 중복
std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "현재 HP는 " << user.GetHP() << "이고, 먹은 아이템은 총 " << user.GetItemCnt() << "개 입니다";
    return os;
}

// Magician 클래스
void Magician::doAttack() const {
    std::cout << "마법 사용!" << std::endl;
}

// Warrior 클래스
void Warrior::doAttack() const {
    std::cout << "베기 사용!" << std::endl;
}
