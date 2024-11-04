/*
    #20303 할로윈의 양아치
*/
#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

int n, m, k, visited[30004], parent[30004], dp[3004], weight[30004], value[30004];
int getRoot(int node){
    if(parent[node] == node) return node;
    return parent[node] = getRoot(parent[node]);
}
void merge(int node1, int node2){
    int r1 = getRoot(node1), r2 = getRoot(node2);
    if(r1 == r2) return;
    weight[r1] += weight[r2];
    value[r1] += value[r2];
    parent[r2] = r1;
}
int main() {
    cin >> n >> m >> k;
    for(int i = 0; i <= n; i++){ parent[i] = i; weight[i] = 1;}
    for(int i = 1; i <= n; i++){
        cin >> value[i];
    }
    int from, to;
    for(int j = 0; j < m; j++){
        cin >> from >> to;
        merge(from, to);
    }
    for(int i = 1; i <= n; i++){
        int root = getRoot(i);
        if(visited[root]) continue;
        int v = value[root], w = weight[root];
        for(int j = k - 1; j >= w; j--){
            dp[j] = max(dp[j], dp[j - w] + v);
        }
        visited[root] = 1;
    }
    cout << dp[k - 1];
    return 0;
}