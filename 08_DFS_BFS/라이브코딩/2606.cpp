#include <iostream>
#include <queue>

using namespace std;
typedef vector<vector<int>> vec_vec;

/*
vector<bool> visited_dfs;

void dfs(int node, vec_vec &graph) {
    visited_dfs[node] = true;

    for(int i = 0; i < graph[node].size(); i++) {
        int next_node = graph[node][i];
        if(!visited_dfs[next_node]) {
            dfs(next_node, graph);
        }
    }
}
*/

int bfs(int n, vec_vec &graph) {
    int cnt = 0;
    vector<bool> visited (n+1, false);
    queue<int> q;

    q.push(1);
    visited[1] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(const auto& next_node : graph[node]) { // ranged based for문으로 하면 보기가 편합니다! 참조 가능한 상황이면 더 빠르니 const auto&를 사용해 보세요!
            if(!visited[next_node]) {
                q.push(next_node);
                visited[next_node] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int n, m, n1, n2;
    vec_vec graph;

    // 입력
    cin >> n >> m;
    graph.assign(n+1, vector<int> (0));
    //visited_dfs.assign(n+1, false);
    while(m--) {
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    // 연산 & 출력
    cout << bfs(n, graph);
    /*dfs(1, graph);
    int cnt = 0;
    for(int i = 2; i <= n; i++) {
        if(visited_dfs[i]) {
            cnt++;
        }
    }
    cout << cnt;*/
    return 0;
}

