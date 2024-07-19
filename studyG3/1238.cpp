/*
    #1238 파티
*/
#include<iostream>
#include<queue>
#include<vector>
#define INF 1e9
using namespace std;

int n, m, x, dist1[1004], dist2[1004], ret = 0;
vector<pair<int, int>> adj1[1004], adj2[1004];
void dijkstra(int dist[1004], vector<pair<int, int>> adj[1004]){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[x] = 0;
    pq.push({0, x});
    int cur, d;
    while(!pq.empty()){
        cur = pq.top().second;
        d = pq.top().first;
        pq.pop();
        if(dist[cur] != d) continue;

        for(auto next : adj[cur]){
            int temp = dist[cur] + next.second;
            if(dist[next.first] > temp){
                dist[next.first] = temp;
                pq.push({temp, next.first});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x;
    int from, to, weight;
    for(int i = 0; i < m; i++){
        cin >> from >> to >> weight;
        adj1[from].push_back({to, weight});
        adj2[to].push_back({from, weight});
    }

    fill(dist1, dist1 + 1004, INF);
    fill(dist2, dist2 + 1004, INF);

    dijkstra(dist1, adj1);
    dijkstra(dist2, adj2);
    for(int i = 1; i <= n; i++){
        if(i != x) ret = max(ret, dist1[i] + dist2[i]);
    }
    cout << ret;
    return 0;
}