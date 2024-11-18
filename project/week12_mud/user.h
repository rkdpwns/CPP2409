#ifndef USER_H
#define USER_H

#include <iostream>

class User {
private:
    int hp;
    int itemCnt;  // 아이템 횟수

public:
    User();
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    int GetHP() const;
    void AddItem();  // 아이템 증가
    int GetItemCnt() const;  // 현재 아이템 반환

    friend std::ostream& operator<<(std::ostream& os, const User& user);
};

#endif
