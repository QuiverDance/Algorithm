/*
    #4963 섬의 개수
*/
#include<iostream>
using namespace std;

int w, h, a[54][54], visited[54][54], ret;
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
int dx[] = {1, 0, -1, 0, -1, 1, -1, 1};
void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 8; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= h || nx >= w || visited[ny][nx])
            continue;
        if(a[ny][nx] == 1)
            dfs(ny, nx);
    }
}

int main(){
    int num;
    while(scanf("%d %d", &w, &h)){
        if(w == 0 && h == 0) break;
        fill(&a[0][0], &a[0][0] + 54 * 54, 0);
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        ret = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                scanf("%d", &num);
                a[i][j] = num;
            }
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(a[i][j] == 0 || visited[i][j]) continue;
                ret++;
                dfs(i, j);
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}