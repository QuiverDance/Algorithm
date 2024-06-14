/*
    #1504 특정한 최단 경로
*/
#include<iostream>
#include<vector>
#include<queue>
#define INF 1e8
using namespace std;

int n, e, ret = INF, dist[3][804];
int v1, v2;
vector<pair<int, int>> adj[804];
void solve(int idx, int st){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st}); dist[idx][st] = 0;

    while(!pq.empty()){
        int cur = pq.top().second; int d = pq.top().first;
        pq.pop();
        if(dist[idx][cur] < d) continue;

        for(auto next : adj[cur]){
            int cost = dist[idx][cur] + next.second;
            if(dist[idx][next.first] > cost){
                dist[idx][next.first] = cost;
                pq.push({cost, next.first});
            }
        }
    }
}

int main(){
    fill(&dist[0][0], &dist[0][0] + 3 * 804, INF);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> e;
    int from, to, weight;
    for(int i = 0; i < e; i++){
        cin >> from >> to >> weight;
        adj[from].push_back({to, weight});
        adj[to].push_back({from, weight});
    }
    cin >> v1 >> v2;

    solve(0, 1);
    solve(1, v1);
    solve(2, v2);
    
    ret = min(ret, min(dist[0][v1] + dist[1][v2] + dist[2][n], dist[0][v2] + dist[2][v1] + dist[1][n]));
    cout << (ret == INF ? -1 : ret);
    return 0;
}