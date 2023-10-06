#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<bool> visited_recur;

vector<int> dfs(int n, int v, vector<vector<bool>> &edge) { //DFS 스택 이용
    vector<int> result;
    vector<bool> visited (n+1, false);
    stack<int> s;

    s.push(v);
    visited[v] = true;
    result.push_back(v);

    while(!s.empty()) {
        int node = s.top();
        bool child = false;

        for(int i = 1; i <= n; i++) {
            if(edge[node][i] && !visited[i]) {
                child = true;
                s.push(i);
                visited[i] = true;
                result.push_back(i);
                break;
            }
        }
        if(!child) {
            s.pop();
        }
    }
    return result;
}
/*
vector<int> dfs_result_2;
void dfsRecur(int n, int node, vector<vector<bool>> &edge) { // DFS 재귀 이용
    visited_recur[node] = true;
    dfs_result_2.push_back(node);

    for(int i = 1; i <= n; i++) {
        if(edge[node][i] && !visited_recur[i]) {
            dfsRecur(n, i, edge);
        }
    }
}
*/

vector<int> bfs(int n, int v, vector<vector<bool>> &edge) { // BFS 큐 이용
    vector<int> result;
    vector<bool> visited (n+1, false);
    queue<int> q;

    q.push(v);
    visited[v] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for(int i = 1; i <= n; i++) {
            if(edge[node][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return result;
}

int main() {
    int n, m, v, n1, n2;
    vector<vector<bool>> edge;

    // 입력
    cin >> n >> m >> v;
    edge.assign(n+1, vector<bool> (n+1, false));
    visited_recur.assign(n+1, false);
    while(m--) {
        cin >> n1 >> n2;
        edge[n1][n2] = true;
        edge[n2][n1] = true;
    }

    // 연산
    vector<int> dfs_result = dfs(n, v, edge);
    //dfsRecur(n, v, edge);
    vector<int> bfs_result = bfs(n, v, edge);

    // 출력
    for(int i : dfs_result) {
        cout << i << ' ';
    }
    /*
    for(int i : dfs_result_2) {
        cout << i << ' ';
    }
     */
    cout << '\n';
    for(int i : bfs_result) {
        cout << i << ' ';
    }
    return 0;
}
