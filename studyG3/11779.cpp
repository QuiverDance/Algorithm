/*
    #11779 최소비용 구하기2
*/
#include<iostream>
#include<queue>
#include<vector>
#define INF 1e9
using namespace std;

int n, m, dist[1004], trace[1004], st, ed;
vector<pair<int, int>> adj[1004];
vector<int> v;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(){
    pq.push({0, st}); dist[st] = 0;
    
    int cur, w;
    while(!pq.empty()){
        cur = pq.top().second;
        w = pq.top().first;
        pq.pop();
        if(dist[cur] != w) continue;

        for(auto next : adj[cur]){
            int cost = w + next.second;
            if(dist[next.first] > cost){
                dist[next.first] = cost;
                trace[next.first] = cur;
                pq.push({cost, next.first});
            }
        }
    }
}

int main() {
    fill(&dist[0], &dist[0] + 1004, INF);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int from, to, weight;
    for(int i = 0; i < m; i++){
        cin >> from >> to >> weight;
        adj[from].push_back({to, weight});
    }
    cin >> st >> ed;
    
    dijkstra();
    
    int cur = ed; v.push_back(ed);
    while(trace[cur] != st){
        v.push_back(trace[cur]);
        cur = trace[cur];
    }
    v.push_back(st);
    
    cout << dist[ed] << '\n' << v.size() << '\n';
    for(int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
    return 0;
}