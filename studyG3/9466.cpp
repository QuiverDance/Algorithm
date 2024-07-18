/*
    #9466 텀 프로젝트
*/
#include<iostream>
#include<cstring>
using namespace std;

int t, n, adj[100004], visited[100004], status[100004], order, cycle;
void dfs(int node){
    visited[node] = order++;
    int next = adj[node];
    if(visited[next] == 0)
        dfs(next);
    else if(!status[next])
        cycle += visited[node] - visited[next] + 1;
    status[node] = true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--){
        memset(visited, 0, sizeof(visited));
        memset(status, 0, sizeof(status));
        order = 1; cycle = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> adj[i];
        for(int i = 1; i <= n; i++){
            if(visited[i]) continue;
            dfs(i);
        }
        cout << n - cycle << '\n';
    }
    return 0;
}