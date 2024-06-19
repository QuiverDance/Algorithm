/*
    #1922 네트워크 연결
*/
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;

int n, m, ret, parent[1004];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

int getRoot(int node){
    if(parent[node] == -1) return node;
    return parent[node] = getRoot(parent[node]);
} 
int main(){
    memset(parent, -1, sizeof(parent));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

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
        parent[getRoot(to)] = getRoot(from);
        ret += weight;
    }
    cout << ret;
    return 0;
}