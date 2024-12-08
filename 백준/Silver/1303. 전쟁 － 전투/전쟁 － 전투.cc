#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

char graph[101][101];
int visited[101][101] = {0, };
int xpos[4] = {0, 0, -1, 1};
int ypos[4] = {-1, 1, 0, 0}; // 순서대로 상 하 좌 우

int n, m, cnt=0;

int cnt_white = 0, cnt_blue = 0;

void dfs_blue(int x, int y) {
    cnt_blue++;
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int currentX = x + xpos[i];
        int currentY = y + ypos[i];
        if (currentX < 0 || currentY < 0 || currentX >= m || currentY >= n)
            continue;
        if (graph[currentX][currentY] == 'B' && !visited[currentX][currentY]) // 인접한 병사의 옷색과 같고 방문 안 하면
            dfs_blue(currentX, currentY);
    }
}
void dfs_white(int x, int y) {
    cnt_white++;
    visited[x][y] = 1;
//    cout << "visit : [" << x << "][" << y << "]" << endl;
    for (int i = 0; i < 4; i++) {
        int currentX = x + xpos[i];
        int currentY = y + ypos[i];
        if (currentX < 0 || currentY < 0 || currentX >= m || currentY >= n)
            continue;
        if (graph[currentX][currentY] == 'W' && !visited[currentX][currentY]) // 인접한 병사의 옷색과 같고 방문 안 하면
            dfs_white(currentX, currentY);
    }
}

int main() {
    cin.tie(NULL)->ios::sync_with_stdio(false);

    int blue=0, white=0;
    char color;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> color;
            graph[i][j] = color;
        }
    }
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                cout << graph[i][j] << " ";
//            }
//            cout << endl;
//        }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 'W' && visited[i][j] == 0){ // 옷색이 white이면 여기서 따로 진행
                cnt_white=0;
                dfs_white(i, j);
//              cout << "cnt_white : " << cnt_white << endl;
                white += cnt_white * cnt_white;
            }
            else if (graph[i][j] == 'B' && visited[i][j] == 0){
                cnt_blue=0;
                dfs_blue(i, j);
                blue += cnt_blue * cnt_blue;
            }
        }
    }
    
    cout << white << " " << blue << endl;
    return 0;
}
