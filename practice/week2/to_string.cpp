#include <iostream>
#include <string>
using namespace std;

int main()
{

    string s1 = "사과";
    string s2;
    // s2 = s1 + " " + 10 + "개";
    s2 = s1 + " " + to_string(10) + "개";
    cout << s2 << endl;
}