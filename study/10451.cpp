/*
    #10451 순열 사이클
*/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int t, n, ret, visited[1004];
vector<int> adj[1004];

void clear(){
    ret = 0;
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < 1004; i++) adj[i].clear();
}

void dfs(int node){
    visited[node] = 1;
    for(int next : adj[node]){
        if(visited[next]) continue;
        dfs(next);
    }
}

int main(){
    cin >> t;
    int num;
    while(t--){
        clear();
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> num;
            adj[i].push_back(num);
        }
        for(int i = 1; i <= n; i++){
            if(visited[i]) continue;
            ret++;
            dfs(i);
        }
        cout << ret << '\n';
    }
    return 0;
}