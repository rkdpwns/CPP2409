#include <iostream>


using namespace std;

const int NUM_USERS = 3;
const int NUM_ITEMS = 3;

void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS]) {
    for (int i = 0; i < NUM_USERS; ++i) {
        cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요 (" << NUM_ITEMS << "개의 항목에 대해): ";
        for (int j = 0; j < NUM_ITEMS; ++j) {
            cin >> preferences[i][j];
        }
    }
}

void findRecommendedItems(const int preferences[NUM_USERS][NUM_ITEMS]) {

    for (int i = 0; i < NUM_USERS; ++i) {
        int maxPreference = preferences[i][0];
        int maxIndices[NUM_ITEMS];
        int maxCount = 1;
        maxIndices[0] = 0;

        for (int j = 1; j < NUM_ITEMS; ++j) {
            if (preferences[i][j] > maxPreference) {
                maxPreference = preferences[i][j];
                maxIndices[0] = j;
                maxCount = 1;
            } else if (preferences[i][j] == maxPreference) {
                maxIndices[maxCount] = j;
                ++maxCount;
            }
        }

        int recommendedIndex = maxIndices[rand() % maxCount];

        cout << "사용자 " << (i + 1) << "에게 추천하는 항목: ";
        cout << (recommendedIndex + 1) << endl;
    }
}

int main() {
    int userPreferences[NUM_USERS][NUM_ITEMS];

    initializePreferences(userPreferences);
    findRecommendedItems(userPreferences);

    return 0;
}
