/*
    #1987 알파벳
*/
#include<iostream>
using namespace std;

int n, m, visited[24][24], alpha[26], ret = 1;
char a[24][24];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void dfs(int y, int x){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(visited[ny][nx] || alpha[a[ny][nx] - 'A']) continue;
        visited[ny][nx] = visited[y][x] + 1;
        alpha[a[ny][nx] - 'A'] = 1;
        ret = max(ret, visited[ny][nx]);
        dfs(ny, nx);
        visited[ny][nx] = 0;
        alpha[a[ny][nx] - 'A'] = 0;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) scanf(" %1c", &a[i][j]);
    }
    
    visited[0][0] = 1; 
    alpha[a[0][0] - 'A'] = 1;
    dfs(0, 0);
    cout << ret;
    return 0;
}