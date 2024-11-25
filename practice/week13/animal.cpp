#include <iostream>
using namespace std;

class Animal
{
public:
    void Speak() { cout << "Animal speak()" << endl; }
};

class Dog : public Animal
{
public:
    int age;
    void Speak() { cout << "멍멍" << endl; }
};

class Cat : public Animal
{
public:
    void Speak() { cout << "야옹" << endl; }
};

int main()
{
    Animal *a1 = new Dog();
    a1->Speak();
   
    Animal a2 = Cat();
    a2.Speak();
    delete a1;
    return 0;
}