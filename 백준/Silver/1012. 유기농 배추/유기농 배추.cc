#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define endl '\n'

int graph[51][51] = {0, };
int visited[51][51] = {0, }; // 방문 여부 확인
int xpos[4] = {0, 0, -1, 1}; // x좌표 이동
int ypos[4] = {-1, 1, 0, 0}; // y좌표 이동
int t, m, n, k, x, y;

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int currentX = x + xpos[i]; // 상하좌우 탐색
        int currentY = y + ypos[i]; // 상하좌우 탐색
        if (currentX < 0 || currentY < 0 || currentX >= m || currentY >= n) // 그래프 범위 넘어서면
            continue;
        if (graph[currentX][currentY] == 1 && !visited[currentX][currentY]) { // 배추가 있고, 한 번도 방문하지 않았다면
            visited[currentX][currentY] = 1;
            dfs(currentX, currentY); // 재귀 ㄱㄱ
        }
    }
}

int main() {
    cin.tie(NULL)->ios::sync_with_stdio(false);
    
    cin >> t;
    for (int i = 0; i < t; i++) {
        int cnt = 0;
        cin >> m >> n >> k;
        for (int j = 0; j < k; j++) {
            cin >> x >> y;
            graph[x][y] = 1; // 해당 그래프 좌표에 배추 넣기
        }
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < n; l++) {
                if (graph[j][l] == 1 && !visited[j][l]) { // 배추가 있고, 한 번도 방문하지 않았다면
                    cnt++; // 배추흰지렁이 개수 추가
                    dfs(j, l); // dfs 진행
                }
            }
        }
        cout << cnt << endl;
        memset(graph, 0, sizeof(graph)); // graph 0으로 초기화
        memset(visited, 0, sizeof(visited)); // visited 0으로 초기화
    }
    return 0;
}

