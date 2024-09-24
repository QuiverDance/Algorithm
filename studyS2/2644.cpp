/*
    #2644 촌수계산
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, t1, t2, visited[104];
vector<int> adj[104];
queue<int> q;
int main(){
    cin >> n >> t1 >> t2 >> m;
    int from, to;
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    q.push(t1); visited[t1] = 1;
    int node;
    while(q.size()){
        node = q.front(); q.pop();
        for(int next : adj[node]){
            if(visited[next]) continue;
            q.push(next); visited[next] = visited[node] + 1;
        }
    }
    if(visited[t2]) cout << visited[t2] - 1;
    else cout << -1;
    return 0;
}