#include<iostream>

using namespace std;

int m, n, board[50][50], visited[50][50];
int cnt, roomSize[2504], ret1, ret2;

int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

int dfs(int y, int x, int g){
    if(visited[y][x]) return 0;
    visited[y][x] = g;
    int ret = 1;
    for(int i = 0; i < 4; i++){
        if(!(board[y][x] & (1 << i))){
            int ny = y + dy[i];
            int nx = x + dx[i];
            ret += dfs(ny, nx, g);
        }
    }
    return ret;
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) cin >> board[i][j];
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j]) continue;
            cnt++;
            roomSize[cnt] = dfs(i, j, cnt);
            ret1 = max(ret1, roomSize[cnt]);
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i + 1 < m){
                int a = visited[i][j];
                int b = visited[i + 1][j];
                if(a != b) ret2 = max(ret2, roomSize[a] + roomSize[b]);
            }
            if(j + 1 < n){
                int a = visited[i][j];
                int b = visited[i][j + 1];
                if(a != b) ret2 = max(ret2, roomSize[a] + roomSize[b]);
            }
        }
    }
    cout << cnt << '\n' << ret1 << '\n' << ret2;
    return 0;
}