#include<iostream>

using namespace std;

int n, m, a, time, cnt, temp;
int board[101][101], visited[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int count(){
    int ret = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 1) ret++;
        }
    }
    return ret;
}
void update(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == -1) board[i][j] = 0;
        }
    }
}
void dfs(int y, int x){
    visited[y][x] = 1;
    for(int d = 0; d < 4; d++){
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(ny < 0 || nx < 0 || ny > n-1 || nx > m-1) continue;
        if(board[ny][nx] == 1){
            board[ny][nx] = -1;
        }
        else if(board[ny][nx] == 0 && !visited[ny][nx]) dfs(ny, nx);
    }
}
int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a;
            board[i][j] = a;
        }
    }
    time = 0; cnt = count();
    while(true){
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
        dfs(0, 0);
        update();
        time++;
        temp = count();
        if(temp > 0)
            cnt = temp;
        else
            break;
    }
    cout << time <<'\n' << cnt;
    return 0;
}