#include<iostream>
#include<string>

using namespace std;

int r, c, k, ret;
string s;
int board[5][5], visited[5][5];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int cnt){
    if(y == 0 && x == c - 1 && cnt == k){
        ret++;
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny > r - 1 || nx > c - 1) continue;
        if(board[ny][nx] == 'T' || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx, cnt + 1);
        visited[ny][nx] = 0;
    }
}

int main(void){
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++){
        cin >> s;
        for(int j = 0; j < c; j++) board[i][j] = s[j];
    }
    visited[r - 1][0] = 1;
    dfs(r - 1, 0, 1);
    cout << ret;
    return 0;
}