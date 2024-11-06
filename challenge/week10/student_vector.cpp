#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> scores;
    int score;
    
    //cout << "성적을 입력하세요 (종료는 -1): " << endl;

    // 성적 입력
    while (true) {
        cout << "성적을 입력하세요 (종료는 -1): ";
        cin >> score;

        if (score == -1) {
            break;  // -1을 입력하면 입력 종료
        }

        scores.push_back(score);  // 입력받은 성적을 벡터에 추가
    }

    // 입력된 성적이 있는지 확인
    if (scores.empty()) {
        cout << "입력된 성적이 없습니다." << endl;
        return 0;
    }

    // 평균 계산
    int sum = 0;
    for (int s : scores) {
        sum += s;
    }
    double average = static_cast<double>(sum) / scores.size();

    // 결과 출력
    cout << "입력된 성적의 평균: " << average << endl;

    return 0;
}
