/*
    #11725 트리의 부모 찾기
*/
#include<iostream>
#include<vector>
using namespace std;

int n, visited[100004], p[100004];
vector<int> adj[100004];
void dfs(int parent, int node){
    visited[node] = parent;
    for(int next : adj[node]){
        if(visited[next]) continue;
        dfs(node, next);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int st, ed;
    for(int i = 0; i < n; i++){
        cin >> st >> ed;
        adj[st].push_back(ed);
        adj[ed].push_back(st);
    }
    dfs(-1, 1);
    for(int i = 2; i <= n; i++){
        cout << visited[i] << '\n';
    }
    return 0;
}