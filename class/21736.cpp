/*
    #21736 헌내기는 친구가 필요해
*/
#include<iostream>
using namespace std;

int n, m, visited[604][604], sy, sx, ret;
char a[604][604];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        if(a[ny][nx] == 'X') continue;
        if(a[ny][nx] == 'P') ret++;
        dfs(ny, nx);
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf(" %1c", &a[i][j]);
            if(a[i][j] == 'I'){
                sy = i;
                sx = j;
            }
        }
    }
    dfs(sy, sx);
    if(ret == 0) printf("TT");
    else printf("%d", ret);
    return 0;
}