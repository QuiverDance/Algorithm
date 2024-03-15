/*
    #18352 특정 거리의 도시 찾기
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m, k, x, visited[300004];
vector<int> adj[300004], v;
queue<int> q;
int main(){
    cin >> n >> m >> k >> x;
    int st, ed;
    for(int i = 0; i < m; i++){
        cin >> st >> ed;
        adj[st].push_back(ed);
    }
    q.push(x); visited[x] = 1;
    int node;
    while(!q.empty()){
        node = q.front(); q.pop();
        for(int next : adj[node]){
            if(visited[next]) continue;
            q.push(next); visited[next] = visited[node] + 1;
        }
    }
    for(int i = 1; i <= n; i++){
        if(visited[i] - 1 == k) v.push_back(i);
    }
    if(v.size() == 0) cout << -1;
    else{
        for(int it : v) cout << it << '\n';
    }
    return 0;
}