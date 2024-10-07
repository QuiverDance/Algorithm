/*
    #1167 트리의 지름
*/
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;

typedef pair<int, int> pii;

int v, visited[100004], ret, maxNode;
vector<pii> adj[100004];
void dfs(int node, int len){
    visited[node] = 1;
    if(ret < len){
        ret = len;
        maxNode = node;
    }
    for(pii next : adj[node]){
        if(visited[next.first]) continue;
        dfs(next.first, len + next.second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v;
    int from, to, weight;
    for(int i = 0; i < v; i++){
        cin >> from;
        while(true){
            cin >> to;
            if(to == -1) break;
            cin >> weight;
            adj[from].push_back({to, weight});
            // adj[to].push_back({from, weight});
        }
    }
    dfs(from, 0);
    memset(visited, 0, sizeof(visited)); ret = 0;
    dfs(maxNode, 0);
    cout << ret;
    return 0;
}