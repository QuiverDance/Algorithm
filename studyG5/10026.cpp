/*
    #10026 적록색약
*/
#include<iostream>
using namespace std;

int n, visited[104][104], a_visited[104][104], ret1, ret2;
char a[104][104];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
        if(a[ny][nx] == a[y][x]) dfs(ny, nx);
    }
}

void a_dfs(int y, int x){
    a_visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || a_visited[ny][nx]) continue;
        if(a[y][x] == 'B'){
            if(a[ny][nx] == a[y][x]) a_dfs(ny, nx);
        }
        else if(a[ny][nx] != 'B'){ 
            a_dfs(ny, nx);
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) scanf(" %1c", &a[i][j]);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                ret1++;
                dfs(i, j);
            }
            if(!a_visited[i][j]){
                ret2++;
                a_dfs(i, j);
            }
        }
    }
    printf("%d %d", ret1, ret2);
    return 0;
}