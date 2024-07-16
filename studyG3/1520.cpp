/*
    #1520 내리막 길 
*/
#include<iostream>
#include<cstring>
using namespace std;

int n, m, a[504][504], dp[504][504];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int dfs(int y, int x){
    if(y == n - 1 && x == m - 1) return 1;
    int& ret = dp[y][x];
    if(ret != -1) return ret;
    
    ret = 0;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i], nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(a[ny][nx] < a[y][x])
            ret += dfs(ny, nx);
    }
    return ret;
}
int main() {
    memset(dp, -1, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    cout << dfs(0, 0);
    return 0;
}