#include<iostream>
#include<string>
#include<queue>
#include<tuple>

using namespace std;

int r, c, ret;
int board[20][20], visited[26];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
string s;

void dfs(int y, int x, int cnt){
    ret = max(ret, cnt);
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny > r - 1 || nx > c - 1) continue;
        if(visited[board[ny][nx] - 'A']) continue;
        visited[board[ny][nx] - 'A'] = 1;
        dfs(ny, nx, cnt + 1);
        visited[board[ny][nx] - 'A'] = 0;
    }
}
int main(void){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        cin >> s;
        for(int j = 0; j < c; j++) board[i][j] = s[j];
    }
    visited[board[0][0] - 'A'] = 1;
    dfs(0, 0, 1);

    cout << ret;
    return 0;
}