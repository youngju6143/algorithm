#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n;

int blindnessCount = 0, generalCount = 0;
// 반시계방향
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int visited_general[101][101];// 방문 여부
int visited_blindness[101][101];// 방문 여부

char color_general[101][101];
char color_blindness[101][101];

void dfs_general(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        
        if (nextX >= 0 || nextX < n || nextY >= 0 || nextY < n) {
            if (visited_general[nextX][nextY] == 0 && (color_general[x][y] == color_general[nextX][nextY])) {
                visited_general[nextX][nextY] = 1;
                dfs_general(nextX, nextY);
            }
        }
    }
}
void dfs_blindness(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        
        if (nextX >= 0 || nextX < n || nextY >= 0 || nextY < n) {
            if (visited_blindness[nextX][nextY] == 0 && color_blindness[x][y] == color_blindness[nextX][nextY]) {
                visited_blindness[nextX][nextY] = 1;
                dfs_blindness(nextX, nextY);
            }
        }
    }
}

int main() {
    cin >> n;
    char color;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> color;
            visited_general[i][j] = 0;
            visited_blindness[i][j] = 0;
            
            color_general[i][j] = color;
            color_blindness[i][j] = color;
            
            if (color == 'G')
                color_blindness[i][j] = 'R';
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited_general[i][j] != 1) {
                generalCount++;
                visited_general[i][j] = 1;
                dfs_general(i, j);
            }
            if (visited_blindness[i][j] != 1) {
                blindnessCount++;
                visited_blindness[i][j] = 1;
                dfs_blindness(i, j);
            }
            
        }
    }
    
    cout << generalCount << " " << blindnessCount << endl;
    return 0;
}