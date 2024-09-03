/*
    #1939 중량제한
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m, dist[100004], st, ed;
vector<pair<int, int>> adj[100004];
priority_queue<pair<int, int>> pq;
void maxDijkstra(){
    for(auto next : adj[st]){
        dist[next.first] = next.second;
        pq.push({next.second, next.first});
    }
    int cur, d;
    while(!pq.empty()){
        cur = pq.top().second;
        d = pq.top().first;
        pq.pop();
        if(d != dist[cur]) continue;
        for(auto next : adj[cur]){
            int cost = min(d, next.second);
            if(dist[next.first] < cost){
                dist[next.first] = cost;
                pq.push({cost, next.first});
            }
        }
    }
}
int main() {
    cin >> n >> m;
    int from, to, weight;
    for(int i = 0; i < m; i++){
        cin >> from >> to >> weight;
        adj[from].push_back({to, weight});
        adj[to].push_back({from, weight});
    }
    cin >> st >> ed;
    maxDijkstra();
    cout << dist[ed];
    return 0;
}