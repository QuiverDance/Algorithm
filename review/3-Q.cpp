#include<iostream>
#include<string>
using namespace std;

int r, c, k, visited[30][30], ret;
char a[30][30];
string s;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int cnt){
    if(cnt > k) return;
    if(y == 0 && x == c - 1 && cnt == k){ ret++; return; }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] || a[ny][nx] == 'T') continue;
        visited[ny][nx] = cnt + 1;
        dfs(ny, nx, cnt + 1);
        visited[ny][nx] = 0;
    }
}

int main(){
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++){
        cin >> s;
        for(int j = 0; j < c; j++) a[i][j] = s[j];
    }
    visited[r - 1][0] = 1;
    dfs(r - 1, 0, 1);
    cout << ret;
    return 0;
}