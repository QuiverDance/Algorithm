#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int n, ret = 1e8, rsum, bsum;
int people[11], area[11];
vector<int> adj[11];

int visited[11];
int dfs(int cur, int value){
    visited[cur] = 1;
    int cnt = 1;
    for(int next : adj[cur]){
        if(area[next] != value) continue;
        if(visited[next]) continue;
        cnt += dfs(next, value);
    }
    return cnt;
}
int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> people[i];
    int a, b;
    for(int i = 1; i <= n; i++){
        cin >> a;
        for(int j = 0; j < a; j++){ 
            cin >> b;
            adj[i].push_back(b);
        }
    }

    for(int i = 1; i < (1 << n) - 1; i++){
        memset(area, 0, sizeof(area));
        memset(visited, 0, sizeof(visited));
        rsum = 0; bsum = 0;
        int i1 = 0, i2 = 0;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)) {
                area[j + 1] = 1;
                rsum += people[j + 1];
                i1 = j + 1;
            }
            else {
                bsum += people[j + 1];
                i2 = j + 1;
            }
        }
        if(dfs(i1, 1) + dfs(i2, 0) == n){
            ret = min(ret, abs(rsum - bsum));
            if(ret == 0) break;
        }

    }
    if(ret == 1e8) cout << "-1";
    else
        cout << ret;
    return 0;
}