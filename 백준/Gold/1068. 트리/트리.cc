#include <iostream>
#include <vector>

using namespace std;

int nodeCount, deletedNode, leafCount = 0, root;
vector<int> tree[51];

int dfs(int currentNode) {
    if (currentNode == deletedNode)
        return -1;

    if (tree[currentNode].empty()) {
        leafCount++;
        return 0;
    }

    int validChild = 0;
    for (int child : tree[currentNode]) {
        if (dfs(child) != -1) {
            validChild++;
        }
    }

    if (validChild == 0)
        leafCount++;

    return 0;
}

int main() {
    cin >> nodeCount;

    for (int i = 0; i < nodeCount; i++) {
        int parent;
        cin >> parent;

        if (parent == -1)
            root = i;
        else
            tree[parent].push_back(i);
    }

    cin >> deletedNode;
    dfs(root);
    cout << leafCount << endl;

    return 0;
}
