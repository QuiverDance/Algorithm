#include<iostream>
#include<string>
using namespace std;

int r, c, a[24][24], visited[26], ret = 1;
string s;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void dfs(int y, int x, int len){
    visited[a[y][x] - 'A'] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[a[ny][nx] - 'A']) continue;
        ret = max(ret, len + 1);
        dfs(ny, nx, len + 1);
        visited[a[ny][nx] - 'A'] = 0;
    }
}

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        cin >> s;
        for(int j = 0; j < c; j++){
            a[i][j] = s[j];
        }
    }
    dfs(0, 0, 1);
    cout << ret;
    return 0;
}