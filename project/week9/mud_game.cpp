#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;
// 사용자 정의 함수
bool checkXY(int user_x, int user_y, int mapX, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y, int& hp, bool& weapon, int& armor, int prev_x, int prev_y);
// 메인  함수
int main() {
    // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { 
		{0, 1, 2, 0, 4},
		{1, 0, 0, 2, 0},
		{0, 0, 0, 0, 0},
		{0, 2, 3, 0, 0},
		{3, 0, 0, 0, 2} 
	};
	//좌표, 체력, 무기, 갑옷
	int user_x = 0;
	int user_y = 0;
	int hp = 20;
	bool weapon = false;
	int armor = 0;

	while (true) {
		string user_input; // 사용자의 입력을 저장할 변수
		cout << "명령어를 입력하세요 (up,down,left,right,map,exit): ";
		cin >> user_input;

		int prev_x = user_x; //중복 체크
        int prev_y = user_y;

		if (user_input == "up") {
            // 위로 한 칸 올라가기
			user_y -= 1;
			if (!checkXY(user_x, user_y, mapX, mapY)) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y = prev_y;
			} else {
					hp -= 1; //체력 -
				cout << "위로 한 칸 올라갑니다. 남은 HP: " << hp << endl;
				displayMap(map, user_x, user_y);
			}
		} else if (user_input == "down") {
            // TODO: 아래로 한 칸 내려가기
			user_y += 1;
			if (!checkXY(user_x, user_y, mapX, mapY)) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y = prev_y;
			} else {
					hp -= 1; //체력 -
				cout << "아래로 한 칸 내려갑니다. 남은 HP: " << hp << endl;
				displayMap(map, user_x, user_y);
			}
		} else if (user_input == "left") {
            // TODO: 왼쪽으로 이동하기
			user_x -= 1;
			if (!checkXY(user_x, user_y, mapX, mapY)) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y = prev_y;
			} else {
				hp -= 1; //체력 -
				cout << "왼쪽으로 이동합니다. 남은 HP: " << hp << endl;
				displayMap(map, user_x, user_y);
			}
		} else if (user_input == "right") {
			user_x += 1;
            // TODO: 오른쪽으로 이동하기
			if (!checkXY(user_x, user_y, mapX, mapY)) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y = prev_y;
			} else {
				hp -= 1;//체력 -
				cout << "오른쪽으로 이동합니다. 남은 HP: " << hp << endl;
				displayMap(map, user_x, user_y);
			}
		} else if (user_input == "map") {

			displayMap(map, user_x, user_y);
		} else if (user_input == "exit") {
			cout << "게임을 종료합니다." << endl;
			break;
		} else {
			cout << "잘못된 입력입니다." << endl;
		}

		if (user_x != prev_x || user_y != prev_y) {
            checkState(map, user_x, user_y, hp, weapon, armor, prev_x, prev_y);
        }

        // 체력이 0 이하인 경우 게임 종료
		if (hp <= 0) {
			cout << "체력이 0 이하입니다. 게임이 종료됩니다." << endl;
			break;
		}
        // 목적지 도달 여부
		if (checkGoal(map, user_x, user_y)) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			break;
		}
	}

	return 0;
}
// 맵과 유저 위치를 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 유저 위치 표시
			} else {
                // 해당 위치의 상태 출력
				switch (map[i][j]) {
					case 0: cout << "      |"; break;
					case 1: cout << "아이템|"; break;
					case 2: cout << "  적  |"; break;
					case 3: cout << " 포션 |"; break;
					case 4: cout << "목적지|"; break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 좌표 유효 체크
bool checkXY(int user_x, int user_y, int mapX, int mapY) {
	return (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY);
}

// 유저 목적지 도달 체크
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	return map[user_y][user_x] == 4;
}

// 유저 상태 체크 (아이템, 적, 포션)
void checkState(int map[][mapX], int user_x, int user_y, int& hp, bool& weapon, int& armor, int prev_x, int prev_y) {
	if (user_x == prev_x && user_y == prev_y) return;
	switch (map[user_y][user_x]) {
		case 1:
			if (rand() % 2 == 0) {
				weapon = true;
				cout << "무기 획득!" << endl;
			} else {
				armor++;
				cout << "갑옷 획득! 현재 갑옷 개수: " << armor << endl;
			}
			break;
		case 2:
			cout << "적을 만났습니다! ";
			if (armor > 0) {
				armor--;
				cout << "갑옷으로 적의 공격을 막았습니다. 남은 갑옷: " << armor << endl;
			} else if (weapon) {
				hp -= 1;
				cout << "무기로 적을 베었습니다. HP -1. 현재 HP: " << hp << endl;
   			 } else {
       			 hp -= 2;
       			 cout << "적에게 공격당했습니다. HP -2. 현재 HP: " << hp << endl;
    		}
			break;
		case 3:
			hp += 2;
			cout << "포션 HP +2. 현재 HP: " << hp << endl;
			break;
	}
}
