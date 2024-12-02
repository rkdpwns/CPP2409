#ifndef USER_H
#define USER_H

#include <iostream>

// User 클래스 선언
class User {
private:
    int hp;
    int itemCnt;  // 아이템 횟수

protected:
    User(int initial_hp);

public:
    virtual ~User() = default;

    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    int GetHP() const;
    void AddItem();
    int GetItemCnt() const;

    virtual void doAttack() const = 0; //가상 함수

    friend std::ostream& operator<<(std::ostream& os, const User& user);
};

// Magician 클래스 선언
class Magician : public User {
public:
    Magician();
    void doAttack() const override;
};

// Warrior 클래스 선언
class Warrior : public User {
public:
    Warrior();
    void doAttack() const override;
};

#endif
