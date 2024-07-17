/*
    #1005 ACM Craft 
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int t, n, k, w, front[1004], cost[1004], ret[1004];
vector<int> adj[1004];
void clear(){
    memset(front, 0, sizeof(front));
    memset(cost, 0, sizeof(cost));
    memset(ret, 0, sizeof(ret));
    for(int i = 0; i <= n; i++) adj[i].clear();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> k;
        int from, to;
        queue<int> q;
        clear();
        
        for(int i = 1; i <= n; i++) cin >> cost[i];
        for(int i = 0; i < k; i++){
            cin >> from >> to;
            adj[from].push_back(to);
            front[to]++;
        }
        cin >> w;
        
        for(int i = 1; i <= n; i++){
            if(front[i] == 0){
                q.push(i); ret[i] = cost[i];
            }
        }

        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int next : adj[cur]){
                front[next]--;
                ret[next] = max(ret[next], ret[cur] + cost[next]);
                if(front[next] == 0) q.push(next);
            }
        }
        cout << ret[w] << '\n';
    }
    return 0;
}