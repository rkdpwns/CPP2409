#include <iostream>
using namespace std;

int main() {
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x, y; // 사용자에게 입력받는 x, y 좌표를 저장하는 변수

    // 보드판 초기화
    for (x = 0; x < numCell; x++) {
        for (y = 0; y < numCell; y++) {
            board[x][y] = ' ';
        }
    }

    // 게임하는 코드
    int k = 0; // 플레이어 체크
    char currentUser = 'X'; // 플레이어 돌 저장
    while (true) {
        // 1. 플레이어 차례 출력
        switch (k % 2) {
        case 0:
            cout << "첫번째 유저(X)의 차례입니다 -> ";
            currentUser = 'X';
            break;
        case 1:
            cout << "두번째 유저(O)의 차례입니다 -> ";
            currentUser = 'O';
            break;
        }

        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        if (x >= numCell || y >= numCell) {
            cout << x << ", " << y << ": ";
            cout << "x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
            continue;
        }
        if (board[x][y] != ' ') {
            cout << x << ", " << y << ": 이미 돌이 있습니다." << endl;
            continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드 판 출력
        for (int i = 0; i < numCell; i++) {
            cout << "---|---|---" << endl;
            for (int j = 0; j < numCell; j++) {
                cout << board[i][j];
                if (j != numCell - 1) {
                    cout << "  |";
                }
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;

        // 6. 빙고 체크 (가로, 세로, 대각선)
        int bingo = 0;

        // 가로 체크
        for (int i = 0; i < numCell; i++) {
            if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
                bingo = 1;
                break;
            }
        }

        // 세로 체크
        for (int i = 0; i < numCell; i++) {
            if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
                bingo = 1;
                break;
            }
        }

        // 대각선 체크
        if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
            bingo = 1;
        }
        if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
            bingo = 1;
        }

        if (bingo == 1) {
            cout << "플레이어 " << currentUser << " 승리!" << endl;
            break; // 게임 종료
        }

        // 7. 보드가 꽉 찼는지 확인
        int full = 1;
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] == ' ') {
                    full = 0;
                    break;
                }
            }
            if (full == 0) break;
        }

        if (full == 1) {
            cout << "무승부입니다. 게임이 종료됩니다." << endl;
            break; // 게임 종료
        }

        k++; // 턴 변경
    }

    return 0;
}
