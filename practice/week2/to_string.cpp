#include <iostream>
#include <string>
using namespace std;

int main()
{

    string s1 = "사과";
    string s2;
    // s2 = s1 + " " + 10 + "개";, 문자열과 정수를 직접적으로 더할 수 없기 때문
    s2 = s1 + " " + to_string(10) + "개";
    cout << s2 << endl;
}