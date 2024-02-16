/*
    #1260 DFS와 BFS
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int n, m, v, visited[1004];
vector<int> adj[1004];
queue<int> q;
void dfs(int node){
    visited[node] = 1;
    cout << node << " ";
    for(int next : adj[node]){
        if(visited[next]) continue;
        dfs(next);
    }
}

int main(){
    cin >> n >> m >> v;
    int from, to;
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    for(int i = 0; i <= n; i++){
        if(adj[i].size() == 0) continue;
        sort(adj[i].begin(), adj[i].end());
    }
    
    dfs(v);
    cout << '\n';
    memset(visited, 0, sizeof(visited));

    q.push(v);
    visited[v] = 1; 
    int node;
    while(!q.empty()){
        node = q.front(); q.pop();
        cout << node << " ";
        for(int next : adj[node]){
            if(visited[next]) continue;
            visited[next] = 1; 
            q.push(next);
        }
    }
    return 0;
}