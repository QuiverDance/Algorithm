/*
    #2623 음악 프로그램
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, front[1004], parent[1004], cnt;
vector<int> adj[1004], v;
queue<int> q;

int main(){
    cin >> n >> m;
    int k, num;
    for(int i = 0; i < m; i++){
        cin >> k >> num;
        int prev = num;
        for(int j = 0; j < k - 1; j++){
            cin >> num;
            adj[prev].push_back(num);
            front[num]++;
            prev = num;
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(front[i] == 0){
            q.push(i); v.push_back(i); cnt++;
        }
    }
    int cur;
    while(!q.empty()){
        cur = q.front(); q.pop();
        for(int next : adj[cur]){
            front[next]--;
            if(front[next] == 0){
                q.push(next); cnt++;
                v.push_back(next);
            }
        }
    }
    if(n != cnt) cout << 0;
    else for(int it : v) cout << it << '\n';
    return 0;
}