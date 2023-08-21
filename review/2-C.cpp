#include<iostream>
#include<cstring>
using namespace std;

int n, a[100][100], visited[100][100], ret = 0;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int h){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
        if(a[ny][nx] >= h) dfs(ny, nx, h);
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
                if(a[i][j] < h || visited[i][j]) continue;
                cnt++;
                dfs(i, j, h);
            }
        }
        ret = max(ret, cnt);
    }
    cout << ret;
    return 0;
}