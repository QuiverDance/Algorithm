/*
    #1865 웜홀
*/
#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

int t, n, m, w, dist[504], flag;
vector<pair<pair<int, int>, int>> edges;
int main() {
    cin >> t;
    while(t--){
        fill(&dist[0], &dist[0] + 504, 1e9);
        edges.clear();
        flag = 0;
        cin >> n >> m >> w;
        int from, to, cost;
        for(int i = 0; i < m; i++){
            cin >> from >> to >> cost;
            edges.push_back({{from, to}, cost});
            edges.push_back({{to, from}, cost});
        }
        for(int i = 0; i < w; i++){
            cin >> from >> to >> cost;
            edges.push_back({{from, to}, -1 * cost});
        }
        dist[1] = 0;
        for(int i = 0; i < n; i++){
            for(auto edge : edges){
                tie(from, to) = edge.first;
                cost = edge.second;
                dist[to] = min(dist[to], dist[from] + cost);
            }
        }
        for(auto edge : edges){
            tie(from, to) = edge.first;
            cost = edge.second;
            if(dist[to] > dist[from] + cost){
                flag = 1;
                break;
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}