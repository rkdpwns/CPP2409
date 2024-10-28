#include <iostream>
using namespace std;

const int numCell = 4;
char board[numCell][numCell];

// 보드판 출력 함수
// TODO 1.2: numCell 숫자에 맞춘 보드판 출력
void printBoard() {
    for (int i = 0; i < numCell; i++) {
        cout << "---";
        for (int j = 0; j < numCell - 1; j++) {
            cout << "|---";
        }
        cout << endl;
        for (int j = 0; j < numCell; j++) {
            cout << " " << board[i][j] << " ";
            if (j < numCell - 1) cout << "|";
        }
        cout << endl;
    }
    cout << "---";
    for (int j = 0; j < numCell - 1; j++) {
        cout << "|---";
    }
    cout << endl;
}

// TODO FUNC 1: isValid 함수 생성 후 호출
// 좌표 유효성 검사 함수
bool isValid(int x, int y) {
    return x >= 0 && x < numCell && y >= 0 && y < numCell && board[x][y] == ' ';
}

// TODO FUNC2: 6.1부터 6.2까지 checkWin 함수 생성 후 호출
// 승리 조건 확인 함수
bool checkWin(char currentUser) {
    // 6.1. 가로/세로 돌 체크하기
    for (int i = 0; i < numCell; i++) {
        bool rowWin = true, colWin = true;
        for (int j = 0; j < numCell; j++) {
            if (board[i][j] != currentUser) rowWin = false;
            if (board[j][i] != currentUser) colWin = false;
        }
        if (rowWin || colWin) return true;
    }

    // 6.2. 대각선을 체크하기
    // TODO 1.3: numCell에 맞춘 대각선 빙고 체크 코드로 확장
    // HINT: for 문
    bool diag1Win = true, diag2Win = true;
    for (int i = 0; i < numCell; i++) {
        if (board[i][i] != currentUser) diag1Win = false;
        if (board[i][numCell - 1 - i] != currentUser) diag2Win = false;
    }
    return diag1Win || diag2Win;
}

int main() {

    int k = 0; // 누구 차례인지 체크하기 위한 변수
    char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 변수
    int x, y = 0; // 사용자에게 xy좌표값을 입력받기 위한 변수
    char players[3] = {'X', 'O', 'Z'}; // 3인용 게임 플레이어 표시

    // 보드판 초기화
    for (int i = 0; i < numCell; i++) {
        for (int j = 0; j < numCell; j++) {
            board[i][j] = ' ';
        }
    }

    // 게임을 무한 반복
    while (true) {
        // 1. 누구 차례인지 출력
        // TODO 1.1: 3인용 게임으로 변경
        char currentUser = players[k % 3];
        cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 차례입니다. -> ";

        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        int x, y;
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        // TODO FUNC 1: isValid 함수 생성 후 호출
        if (!isValid(x, y)) {
            cout << "유효하지 않은 입력입니다. 다시 입력해주세요." << endl;
            continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드 판 출력
        // TODO 1.2: numCell 숫자에 맞춘 보드판 출력
        printBoard();

        bool isWin = false; // 승리 여부
        // TODO FUNC2: 6.1부터 6.2까지 checkWin 함수 생성 후 호출
        // 6.1. 가로/세로 돌 체크하기 및 6.2. 대각선 체크하기
        if (checkWin(currentUser)) {
            cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
            break;
        }

        // 7. 모든 칸 다 찼는지 체크하기
        bool isDraw = true;
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] == ' ') {
                    isDraw = false;
                    break;
                }
            }
            if (!isDraw) break;
        }
        if (isDraw) {
            cout << "모든 칸이 다 찼습니다. 무승부로 종료합니다." << endl;
            break;
        }

        k++; // 다음 차례로 넘어가기
    }

    return 0;
}
