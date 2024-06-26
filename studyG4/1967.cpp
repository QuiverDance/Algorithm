/*
    #1967 트리의 지름
*/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, node1, ret, visited[10004];
vector<pair<int, int>> adj[10004];
void dfs(int node, int len){
    visited[node] = 1;
    if(ret < len){
        ret = len;
        node1 = node;
    }
    for(auto it : adj[node]){
        if(visited[it.first]) continue;
        dfs(it.first, len + it.second);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int from, to, weight;
    for(int i = 0; i < n - 1; i++){
        cin >> from >> to >> weight;
        adj[from].push_back({to, weight});
        adj[to].push_back({from, weight});
    }

    dfs(1, 0);
    memset(visited, 0, sizeof(visited)); ret = 0;
    dfs(node1, 0);
    cout << ret;
    return 0;
}