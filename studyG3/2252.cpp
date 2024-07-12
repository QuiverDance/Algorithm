/*
    #2252 줄 세우기
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m, front[32004];
vector<int> adj[32004];
queue<int> q;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int from, to;
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        adj[from].push_back(to);
        front[to]++;
    }
    for(int i = 1; i <= n; i++){
        if(front[i] == 0) q.push(i);
    }
    int cur;
    while(!q.empty()){
        cur = q.front(); q.pop();
        cout << cur << " ";
        for(int next : adj[cur]){
            front[next]--;
            if(front[next] == 0) q.push(next);
        }
    }
    return 0;
}