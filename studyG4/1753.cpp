/*
    #1753 최단경로
*/
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#define INF 1e9
using namespace std;

int v, e, dist[20004], st;
vector<int> adj[20004];
map<pair<int, int>, int> mp;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> v >> e >> st;
    
    int from, to, weight;
    for(int i = 0; i < e; i++){
        cin >> from >> to >> weight;
        adj[from].push_back(to);
        if(mp[{from, to}] == 0 || mp[{from, to}] > weight)
            mp[{from, to}] = weight;
    }

    fill(&dist[0], &dist[0] + 20004, INF);
    pq.push({0, st}); dist[st] = 0;
    
    while(!pq.empty()){
        int cur = pq.top().second; int d = pq.top().first;
        pq.pop();
        if(dist[cur] < d) continue;

        for(int next : adj[cur]){
            int cost = dist[cur] + mp[{cur, next}];
            if(dist[next] > cost){
                dist[next] = cost;
                pq.push({cost, next});
            }
        }
    }

    for(int i = 1; i <= v; i++){
        if(dist[i] == 1e9) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
    return 0;
}