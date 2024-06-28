/*
    #1707 이분 그래프
*/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int t, n, m, visited[20004], flag;
vector<int> adj[20004];
void clear(){
    for(int i = 1; i <= n; i++)
        adj[i].clear();
}
void dfs(int node, int team){
    visited[node] = team;
    for(int next : adj[node]){
        if(visited[next]){
            if(visited[next] == team) flag = 1;
            continue;
        }
        dfs(next, (team == 1 ? 2 : 1));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    int from, to;
    while(t--){
        cin >> n >> m;
        clear(); flag = 0;
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < m; i++){
            cin >> from >> to;
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
        for(int i = 1; i <= n; i++){
            if(visited[i]) continue;
            dfs(i, 1);
        }
        cout << (flag == 0 ? "YES\n" : "NO\n");
    }
    
    return 0;
}