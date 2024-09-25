#include <iostream>
using namespace std;

int main() {
    int vowel = 0;    
    int consonant = 0; 
    char ch;            

    cout << "영문자를 입력하고 ctrl+z를 치세요" << endl;

    while (cin >> ch) {
       if (ch >= 'A' && ch <= 'Z') {
            cout << "영문 대문자는 입력할 수 없습니다. 소문자로 입력해 주세요." << endl;
            continue;
       }

        if (ch >= 'a' && ch <= 'z') {
            switch (ch) {
                // 모음
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowel++;
                    break;
                // 자음
                default:
                    consonant++;
                    break;
            }
        }else {
            cout << "잘못된 입력입니다. 영문 소문자만 입력해 주세요." << endl;
        }
    }

    cout << "모음: " << vowel << endl;
    cout << "자음: " << consonant << endl;

    return 0;
}
