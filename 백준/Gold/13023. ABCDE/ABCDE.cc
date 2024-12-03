#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define endl '\n'

vector<vector<int>> graph(2001);
vector<int> visited(2001);
vector<int> tmp;
int ans = 0;

void dfs(int x, int len) {
    if (len == 4) {
        ans = 1;
        return;
    }
    visited[x] = 1;
    for (int i = 0; i < graph[x].size(); i++) {
        if (!visited[graph[x][i]] && ans == 0) {
            dfs(graph[x][i], len+1);
        }
    }
    visited[x] = 0;
}

int main() {
    cin.tie(NULL)->ios::sync_with_stdio(false);

    int n, m, a, b; // n : 노드 개수, m : 간선 개수
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        dfs(i, 0);
        fill(visited.begin(), visited.end(), 0); // 시작 노드가 매번 바뀌기 때문에 처음 DFS를 실행해주는 것이므로 시작 노드가 바뀔 때마다 visited를 초기화시켜야 함
        if (ans)
            break;
    }
    cout << ans << endl;
    return 0;
}
