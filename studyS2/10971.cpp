/*
    #10971 외판원 순회2
*/
#include<iostream>
using namespace std;

int n, a[14][14], ret = 1e9;
void dfs(int node, int visited, int cost, int start){
    if(visited == (1 << n) - 1){
        if(a[node][start] != 0)
            ret = min(ret, cost + a[node][start]);
        return;
    }
    for(int next = 0; next < n; next++){
        if(a[node][next] == 0 || visited & (1 << next)) continue;
        dfs(next, visited | (1 << next), cost + a[node][next], start);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    for(int i = 0; i < n; i++){
        dfs(i, 1 << i, 0, i);
    }
    cout << ret;
    return 0;
}