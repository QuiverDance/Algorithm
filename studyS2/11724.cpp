/*
    #11724 연결 요소의 개수
*/
#include<iostream>
#include<vector>
using namespace std;

int n, m, visited[1004], ret;
vector<int> adj[1004];

void dfs(int node){
    visited[node] = 1;
    for(int next : adj[node]){
        if(visited[next]) continue;
        dfs(next);
    }
}
int main(){
    cin >> n >> m;
    int from, to;
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        ret++;
        dfs(i);
    }
    cout << ret;
    return 0;
}