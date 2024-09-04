/*
    #2533 사회망 서비스(SNS)
*/
#include<iostream>
#include<vector>
using namespace std;

int n, visited[1000004], dp[1000004][2];
vector<int> adj[1000004];
void dfs(int node){
    visited[node] = 1;
    dp[node][0] = 0;
    dp[node][1] = 1;
    for(int next : adj[node]){
        if(visited[next]) continue;
        dfs(next);
        dp[node][0] += dp[next][1];
        dp[node][1] += min(dp[next][0], dp[next][1]);
    }
}

int main(){
    cin >> n;
    int from, to;
    for(int i = 0; i < n; i++){
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    dfs(1);
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}