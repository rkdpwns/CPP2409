#ifndef USER_H
#define USER_H

class User {
private:
    int hp;

public:
    User();
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    int GetHP() const;
};

#endif
