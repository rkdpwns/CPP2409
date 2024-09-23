#include <iostream>
using namespace std;

int main()
{
    int a, b, c, largest ;
    cout << "3개의 정수를 입력하시오: ";
    cin >> a >> b >> c;

    if (a > b && a > c)
        largest = a;
    else if (b > a && b > c)
        largest = b;
    else if (a == b && b > c) { //동일한 정수 입력
        largest = b;
        cout << "a와 b가 가장 큰 정수입니다";
    }
    else if (a == c && c > b) { //동일한 정수 입력
        largest = a;
        cout << "a와 c가 가장 큰 정수입니다";
    }
     else if (b == c && b > a) { //동일한 정수 입력
        largest = b;
        cout << "b와 c가 가장 큰 정수입니다";
    }
    else if (a == b && b == c) { //동일한 정수 입력
        largest = a;
        cout << "동일한 정수입니다";
    }
    else
        largest = c;

    cout << "가장 큰 정수는" << largest << endl;
    return 0;
}