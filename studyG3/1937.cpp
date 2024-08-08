/*
    #1937 욕심쟁이 판다
*/
#include<iostream>
using namespace std;

int n, a[504][504], dp[504][504], ret;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int dfs(int y, int x){
    int &cur = dp[y][x];
    if(cur != 0) return cur;

    cur = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(a[ny][nx] > a[y][x])
            cur = max(cur, dfs(ny, nx) + 1);
    }
    return cur;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }

    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            ret = max(ret, dfs(y, x));
        }
    }
    cout << ret << '\n';
}