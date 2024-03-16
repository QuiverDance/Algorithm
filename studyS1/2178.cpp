/*
    #2178 미로 탐색
*/
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int n, m, a[104][104], visited[104][104];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> q;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            scanf("%1d", &a[i][j]);
    }
    q.push({1, 1}); visited[1][1] = 1;
    int y, x;
    while(!q.empty()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 1 || nx < 1 || ny > n || nx > m || visited[ny][nx]) continue;
            if(a[ny][nx] == 1){
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }

        }
    }
    cout << visited[n][m];
    return 0;
}