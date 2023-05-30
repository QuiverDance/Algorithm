#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int n, m, cnt, flag;
string s;
int board[300][300], visited[300][300];
pair<int, int> jpos, tpos;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    if(y == tpos.first && x == tpos.second){
        flag = 1;
        return;
    }
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny > n - 1 || nx > m - 1) continue;
        if(visited[ny][nx]) continue;
        if(board[ny][nx] == '1'){
            visited[ny][nx] = 1;
            board[ny][nx] = '0';
        }
        else dfs(ny, nx);
    }
}

int main(void){
    int x1, y1, x2, y2;
    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;
    jpos = {y1-1, x1-1};
    tpos = {y2-1, x2-1};
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            board[i][j] = s[j];
        }
    }
    flag = 0; cnt = 0;
    while(!flag){
        cnt++;
        memset(visited, 0, sizeof(visited));
        dfs(jpos.first, jpos.second);
    }
    cout << cnt;
    return 0;
}