/*
    #1916 최소비용 구하기
*/
#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;

int n, m, dist[1004], visited[1004], adj[1004][1004];
int getNextNode(){
    int mn = INF;
    int idx = 1;
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        if(dist[i] < mn){
            mn = dist[i];
            idx = i;
        }
    }
    return idx;
}

int main() {
    fill(&adj[0][0], &adj[0][0] + 1004 * 1004, INF);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    int st, ed, w;
    for(int i = 0; i < m; i++){
        cin >> st >> ed >> w;
        adj[st][ed] = min(adj[st][ed], w);
    }
    cin >> st >> ed;
    for(int i = 1; i <= n; i++) dist[i] = adj[st][i];
    dist[st] = 0; visited[st] = 1;

    for(int i = 0; i < n - 1; i++){
        int cur = getNextNode();
        visited[cur] = 1;
        for(int j = 1; j <= n; j++){
            if(visited[j]) continue;
            dist[j] = min(dist[j], dist[cur] + adj[cur][j]);
        }
    }
    cout << dist[ed];
    return 0;
}