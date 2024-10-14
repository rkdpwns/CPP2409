#include <iostream>
#include <string>
using namespace std;

// 소문자로 변환
string toLowerStr(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
    return str;
}

// 대문자로 변환
string toUpperStr(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
    }
    return str;
}

int calcHammingDist(string s1, string s2) {
    s1 = toLowerStr(s1);
    s2 = toLowerStr(s2);
    
    int count = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            count += 1;
        }
    }
    return count;
}

int main() {
    string s1, s2;
    
    do {
        cout << "s1 = ";
        cin >> s1;
        cout << "s2 = ";
        cin >> s2;

        if (s1.length() != s2.length()) {
            cout << "오류: 길이가 다릅니다." << endl;
        }
    } while (s1.length() != s2.length());

    int hammingDistance = calcHammingDist(s1, s2);
    cout << "해밍 거리는 " << hammingDistance << "입니다." << endl;

    return 0;
}
