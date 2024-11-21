#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define endl '\n'

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int graph[51][51] = {0, }; // 그래프
int visited[51][51] = {0, }; // 방문 여부
int t, m, n, k;

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i]; 

        // 그래프 범위를 벗어나거나 이미 방문한 경우 무시
        if (nextX < 0 || nextY < 0 || nextX >= m || nextY >= n)
            continue;

        // 배추가 있고 방문하지 않은 경우
        if (graph[nextX][nextY] == 1 && !visited[nextX][nextY]) {
            visited[nextX][nextY] = 1;
            dfs(nextX, nextY);
        }
    }
}

int main() {
    cin.tie(NULL)->ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> m >> n >> k;

        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            graph[x][y] = 1;
        }

        int wormCount = 0;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (graph[x][y] == 1 && !visited[x][y]) {
                    wormCount++;
                    visited[x][y] = 1;
                    dfs(x, y);
                }
            }
        }
        cout << wormCount << endl;
    }

    return 0;
}
