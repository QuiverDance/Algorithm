/*
    #15681 트리와 쿼리
*/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, r, q, dp[100004], visited[100004];
vector<int> adj[100004];
int dfs(int node){
    visited[node] = 1;
    int &ret = dp[node];
    if(ret != -1) return ret;
    ret = 1;
    for(int next : adj[node]){
        if(visited[next]) continue;
        ret += dfs(next);
    }
    return ret;
}
int main() {
    memset(dp, -1, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> r >> q;
    int u, v;
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(r);
    for(int i = 0; i < q; i++){
        cin >> u;
        cout << dp[u] << '\n';
    }
    return 0;
}