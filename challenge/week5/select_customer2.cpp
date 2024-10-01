#include <iostream>
#include <string>

using namespace std;

int main() {
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;
    for (int i = 0; i < maxPeople; i++) {
        cout << "사람 " << i + 1 << "의 이름: ";
        cin >> names[i];
        cout << "사람 " << i + 1 << "의 나이: ";
        cin >> ages[i];
    }

    while (1) {
        int choice;
        cout << "\n메뉴를 선택하세요:" << endl;
        cout << "1. 가장 나이가 많은 사람 출력" << endl;
        cout << "2. 가장 나이가 적은 사람 출력" << endl;
        cout << "3. 종료" << endl;
        cin >> choice;

        if (choice == 1) {
            int maxAge = ages[0];
            for (int i = 1; i < maxPeople; i++) {
                if (ages[i] > maxAge) {
                    maxAge = ages[i];
                }
            }

            cout << "가장 나이가 많은 사람:" << endl;
            for (int i = 0; i < maxPeople; i++) {
                if (ages[i] == maxAge) {
                    cout << names[i] << " (" << ages[i] << "세)" << endl;
                }
            }
        }
        else if (choice == 2) {
            int minAge = ages[0];
            for (int i = 1; i < maxPeople; i++) {
                if (ages[i] < minAge) {
                    minAge = ages[i];
                }
            }

            cout << "가장 나이가 적은 사람:" << endl;
            for (int i = 0; i < maxPeople; i++) {
                if (ages[i] == minAge) {
                    cout << names[i] << " (" << ages[i] << "세)" << endl;
                }
            }
        }
        else if (choice == 3) {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else {
            cout << "잘못된 입력입니다. 프로그램을 종료합니다." << endl;
            break;
        }
    }

    return 0;
}
