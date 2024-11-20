#ifndef USER_H
#define USER_H

#include <iostream>

class User {
private:
    int hp;
    int itemCnt;  // 아이템 횟수

public:
    User();
    virtual ~User() = default;
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    int GetHP() const;
    void AddItem();  // 아이템 증가
    int GetItemCnt() const;  // 현재 아이템 반환

    virtual void doAttack() const; // 가상 함수

    friend std::ostream& operator<<(std::ostream& os, const User& user);
};

// Magician
class Magician : public User {
public:
    void doAttack() const override; 
};

// Warrior
class Warrior : public User {
public:
    void doAttack() const override; 
};

#endif
