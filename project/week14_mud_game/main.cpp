#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>
#include "user.h"

using namespace std;

// 전역 상수
const int mapX = 5;
const int mapY = 5;

vector<vector<int>> loadMapFromFile(const string& filename) {
    vector<vector<int>> map;
    ifstream file(filename);

    if (!file.is_open()) {
        throw runtime_error("맵 파일을 열 수 없습니다. 파일 경로를 확인하세요.");
    }

    for (int i = 0; i < mapY; ++i) {
        vector<int> row;
        for (int j = 0; j < mapX; ++j) {
            int value;
            if (!(file >> value)) {
                throw runtime_error("맵 데이터가 잘못되었습니다.");
            }
            row.push_back(value);
        }
        map.push_back(row);
    }

    if (map.size() != mapY || map[0].size() != mapX) {
        throw runtime_error("맵 데이터 크기가 다릅니다.");
    }

    return map;
}



// 함수 선언
bool checkXY(int user_x, int user_y, int mapX, int mapY);
void displayMap(const vector<vector<int>>& map, int user_x, int user_y);
bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y);
void checkState(vector<vector<int>>& map, int user_x, int user_y, User& user, bool& weapon, int& armor, int prev_x, int prev_y);
bool CheckUser(User* user);


int main() {
    
   vector<vector<int>> map;

    try {
        map = loadMapFromFile("map.txt");
        cout << "맵이 성공적으로 로드되었습니다." << endl;
    } catch (const exception& e) {
        cerr << "오류: " << e.what() << endl;
        return 1;
    }

    // 맵 출력 (테스트용)
    for (int i = 0; i < mapY; ++i) {
        for (int j = 0; j < mapX; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    // 시작 위치 및 상태 초기화
    int user_x = 0;
    int user_y = 0;
    bool weapon = false;
    int armor = 0;

    User* player = nullptr;

    // 직업 선택
    int choice;
    cout << "직업을 선택하세요 (1: Magician, 2: Warrior): ";
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cin.clear(); // 스트림 상태 플래그 초기화
        cin.ignore(1000, '\n');
        cout << "잘못된 입력입니다. 1 또는 2를 입력하세요: ";
    }

    try {
        if (choice == 1) {
            player = new Magician();
            cout << "Magician을 선택했습니다!" << endl;
        } else if (choice == 2) {
            player = new Warrior();
            cout << "Warrior를 선택했습니다!" << endl;
        }
    } catch (const bad_alloc& e) {
        cerr << "메모리 할당 오류: " << e.what() << endl;
        return 1;
    }


    // 게임 루프 시작
    while (true) {
        string user_input;
        cout << "명령어를 입력하세요 (up, down, left, right, info, map, exit): ";
        cin >> user_input;

        int prev_x = user_x;
        int prev_y = user_y;

        // 명령 처리
        if (user_input == "up") {
            user_y -= 1;
            if (!checkXY(user_x, user_y, mapX, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y = prev_y;
            } else {
                player->DecreaseHP(1);
                cout << "위로 이동. 남은 HP: " << player->GetHP() << endl;
                displayMap(map, user_x, user_y);
            }
        } else if (user_input == "down") {
            user_y += 1;
            if (!checkXY(user_x, user_y, mapX, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y = prev_y;
            } else {
                player->DecreaseHP(1);
                cout << "아래로 이동. 남은 HP: " << player->GetHP() << endl;
                displayMap(map, user_x, user_y);
            }
        } else if (user_input == "left") {
            user_x -= 1;
            if (!checkXY(user_x, user_y, mapX, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x = prev_x;
            } else {
                player->DecreaseHP(1);
                cout << "왼쪽으로 이동. 남은 HP: " << player->GetHP() << endl;
                displayMap(map, user_x, user_y);
            }
        } else if (user_input == "right") {
            user_x += 1;
            if (!checkXY(user_x, user_y, mapX, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x = prev_x;
            } else {
                player->DecreaseHP(1);
                cout << "오른쪽으로 이동. 남은 HP: " << player->GetHP() << endl;
                displayMap(map, user_x, user_y);
            }
        } else if (user_input == "map") {
            displayMap(map, user_x, user_y);
        } else if (user_input == "info") {
            cout << *player << endl;
        } else if (user_input == "exit") {
            cout << "게임을 종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다." << endl;
        }

        // 상태 업데이트
        if (user_x != prev_x || user_y != prev_y) {
            checkState(map, user_x, user_y, *player, weapon, armor, prev_x, prev_y);
        }

        if (!CheckUser(player)) {
            cout << "체력이 0 이하입니다. 게임 종료." << endl;
            break;
        }

        if (checkGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            break;
        }
    }

    delete player; // 동적 할당 해제
    return 0;
}

void displayMap(const vector<vector<int>>& map, int user_x, int user_y) {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |";
            } else {
                switch (map[i][j]) {
                    case 0: cout << "      |"; break;
                    case 1: cout << "아이템|"; break;
                    case 2: cout << "  적  |"; break;
                    case 3: cout << " 포션 |"; break;
                    case 4: cout << "목적지|"; break;
                }
            }
        }
        cout << endl << " -------------------------------- " << endl;
    }
}

bool checkXY(int user_x, int user_y, int mapX, int mapY) {
    return (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY);
}

bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y) {
    return map[user_y][user_x] == 4;
}

void checkState(vector<vector<int>>& map, int user_x, int user_y, User& user, bool& weapon, int& armor, int prev_x, int prev_y) {
    if (user_x == prev_x && user_y == prev_y) return;

    switch (map[user_y][user_x]) {
        case 1:
            if (rand() % 2 == 0) {
                weapon = true;
                cout << "무기를 획득했습니다!" << endl;
            } else {
                armor++;
                cout << "갑옷을 획득했습니다! 현재 갑옷 개수: " << armor << endl;
            }
            user.AddItem();
            break;
        case 2:
            cout << "적을 만났습니다! ";
            user.doAttack();
            if (armor > 0) {
                armor--;
                cout << "갑옷으로 적의 공격을 막았습니다. 남은 갑옷: " << armor << endl;
            } else if (weapon) {
                user.DecreaseHP(1);
                cout << "무기로 적을 공격했습니다. HP -1. 남은 HP: " << user.GetHP() << endl;
            } else {
                user.DecreaseHP(2);
                cout << "적에게 공격당했습니다. HP -2. 남은 HP: " << user.GetHP() << endl;
            }
            break;
        case 3:
            user.IncreaseHP(2);
            cout << "포션을 마셨습니다! HP +2. 남은 HP: " << user.GetHP() << endl;
            break;
    }
}

bool CheckUser(User* user) {
    return user->GetHP() > 0;
}