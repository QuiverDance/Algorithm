#include<iostream>
#include<cstring>

using namespace std;

int t, m, n, k, a, b, cnt = 0;
int map[50][50], visited[50][50];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny > n-1 || nx > m-1) continue;

        if(map[ny][nx] == 1 && visited[ny][nx] == 0)
            dfs(ny, nx);
    }
}

int main(void){
    cin >> t;
    while(t--){
        cin >> m >> n >> k;
        for(int i = 0; i < k; i++){
            cin >> a >> b;
            map[b][a] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(map[i][j] == 1 && visited[i][j] == 0){
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << '\n';
        cnt = 0;
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}