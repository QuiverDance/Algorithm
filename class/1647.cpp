/*
    #1647 도시 분할 계획
*/
#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;

typedef pair<int, pair<int, int>> piii;
int n, m, parent[100004], ret, last;
priority_queue<piii, vector<piii>, greater<piii>> pq;
int getRoot(int node){
    if(node == parent[node]) return node;
    return parent[node] = getRoot(parent[node]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i <= n; i++) parent[i] = i;
    
    int from, to, weight;
    for(int i = 0; i < m; i++){
        cin >> from >> to >> weight;
        pq.push({weight, {from, to}});
    }

    while(!pq.empty()){
        weight = pq.top().first;
        tie(from, to) = pq.top().second;
        pq.pop();
        if(getRoot(from) == getRoot(to)) continue;
        ret += weight;
        last = weight;
        parent[getRoot(to)] = getRoot(from);
    }
    cout << ret - last;
    return 0;
}