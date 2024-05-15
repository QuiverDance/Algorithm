/*
    #13023 ABCDE
*/
#include<iostream>
#include<vector>
using namespace std;

int n, m, visited[2004], flag;
vector<int> adj[2004];
void dfs(int node, int depth){
    if(depth == 4){
        flag = 1; return;
    }
    for(int next : adj[node]){
        if(visited[next]) continue;
        visited[next] = 1;
        dfs(next, depth + 1);
        visited[next] = 0;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int from, to;
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    for(int i = 0; i < n; i++){
        visited[i] = 1;
        dfs(i, 0);
        visited[i] = 0;
        if(flag) break;
    }
    cout << (flag == 0 ? 0 : 1);
    return 0;
}