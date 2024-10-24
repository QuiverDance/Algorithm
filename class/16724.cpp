/*
    #16724 피리 부는 사나이
*/
#include<iostream>
#include<string>
using namespace std;

int n, m, ret, visited[1004][1004];
char a[1004][1004];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int getDir(int dir){
    if(dir == 'U') return 0;
    else if(dir == 'R') return 1;
    else if(dir == 'D') return 2;
    else return 3;
}
void dfs(int y, int x, int cnt){
    visited[y][x] = cnt;
    int d = getDir(a[y][x]);
    int ny = y + dy[d];
    int nx = x + dx[d];
    if(visited[ny][nx] == 0){ dfs(ny, nx, cnt); return;}
    if(visited[ny][nx] == cnt) ret++;
}
int main() {
    cin >> n >> m;
    string str;
    for(int i = 0; i < n; i++){
            cin >> str;
        for(int j = 0; j < m; j++){
            a[i][j] = str[j];
        }
    }
    int t = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j]) continue;
            dfs(i, j, ++t);
        }
    }
    cout << ret;
    return 0;
}