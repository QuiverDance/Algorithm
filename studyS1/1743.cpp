/*
    #1743 음식물 피하기
*/
#include <iostream>
using namespace std;

int n, m, k, ret, a[104][104], visited[104][104];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int dfs(int y, int x){
    visited[y][x] = 1;
    int cnt = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(visited[ny][nx] || a[ny][nx] == 0) continue;
        cnt += dfs(ny, nx);
    }
    return cnt;
}

int main() {
    cin >> n >> m >> k;
    int x, y;
    for(int i = 0; i < k; i++){
        cin >> y >> x;
        a[--y][--x] = 1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] || a[i][j] == 0) continue;
            ret = max(ret, dfs(i, j));
        }
    }
    cout << ret;
    return 0;
}