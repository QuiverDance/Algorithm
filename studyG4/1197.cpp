/*
    #1197 최소 스패닝 트리
*/
#include<iostream>
#include<queue>
#include<tuple>
#include<vector>
using namespace std;

int v, e, ret, parent[10004];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int findParent(int node){
    if(node == parent[node]) return node;
    return parent[node] = findParent(parent[node]);
}

int main(){
    cin.tie(NULL);
    cin >> v >> e;
    for(int i = 0; i <= v; i++) parent[i] = i;
    
    int from, to, weight;
    for(int i = 0; i < e; i++){
        cin >> from >> to >> weight;
        pq.push({weight, {from, to}});
    }

    while(!pq.empty()){
        weight = pq.top().first;
        tie(from, to) = pq.top().second;
        pq.pop();
        int pa1 = findParent(from);
        int pa2 = findParent(to);
        if(pa1 == pa2) continue;
        ret += weight;
        parent[pa2] = pa1;
    }
    cout << ret;
    return 0;
}