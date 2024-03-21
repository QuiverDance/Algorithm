/*
    #2468 안전 영역
*/
#include<iostream>
#include<cstring>
using namespace std;

int n, a[104][104], visited[104][104], ret;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void dfs(int y, int x, int h){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(y < 0 || x < 0 || ny >= n || nx >= n) continue;
        if(visited[ny][nx] || a[ny][nx] <= h) continue;
        dfs(ny, nx, h);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    
    for(int h = 0; h <= 100; h++){
        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] || a[i][j] <= h) continue;
                cnt++;
                dfs(i, j, h);
            }
        }
        ret = max(ret, cnt);
    }
    cout << ret;
    return 0;
}