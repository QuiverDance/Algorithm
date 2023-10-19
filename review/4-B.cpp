#include<iostream>
#include<vector>
using namespace std;

int n, a[11], ret = 1e9;
vector<int> adj[11];

int dfs(int cur, int visited, int tcase){
    visited |= (1 << cur);
    int cnt = 1;
    for(int next : adj[cur]){
        if(tcase & (1 << cur) != tcase & (1 << next) || visited & (1 << next)) continue;
        cnt += dfs(next, visited, tcase);
    }
    return cnt;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int k, num;
    for(int i = 0; i < n; i++){
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> num;
            adj[i].push_back(num);
        }
    }
    for(int i = 0; i < (1 << n); i++){
        vector<int> r, b;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)) r.push_back(j);
            else b.push_back(j);
        }
        if(r.empty() || b.empty()) continue;
        int r_cnt = dfs(r[0], 0, i);
        int b_cnt = dfs(b[0], 0, i);
        if(r_cnt != r.size() || b_cnt != b.size()) continue;
        int sum = 0;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)) sum += a[j];
            else sum -= a[j];
        }
        ret = min(ret, abs(sum));
    }
    if(ret == 1e9){
        cout << -1; return 0;
    }
    cout << ret;

    return 0;
}