#include <iostream>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int visited[104][104];// 방문 여부
int maze[104][104];
int N, M;

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            maze[i][j] = line[j] - '0';
        }
    }

    queue<pair<int, int>> bfsQueue;
    bfsQueue.push({0, 0});
    visited[0][0] = 1;

    while (!bfsQueue.empty()) {
        int currentX = bfsQueue.front().first;
        int currentY = bfsQueue.front().second;
        bfsQueue.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];

            if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M)
                continue;

            if (maze[nextX][nextY] == 1 && visited[nextX][nextY] == 0) {
                bfsQueue.push({nextX, nextY});
                visited[nextX][nextY] = visited[currentX][currentY] + 1; // 거리 갱신
            }
        }
    }

    cout << visited[N - 1][M - 1] << endl;

    return 0;
}
