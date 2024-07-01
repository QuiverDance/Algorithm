/*
    #1261 알고스팟
*/
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int n, m, a[104][104], visited[104][104];
queue<pair<int, int>> q;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int main() {
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            scanf("%1d", &a[i][j]);
    }
    q.push({0, 0}); visited[0][0] = 1;
    int y, x;
    while(!q.empty()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visited[ny][nx] && visited[ny][nx] <= visited[y][x] + a[ny][nx])
                continue;
            visited[ny][nx] = visited[y][x] + a[ny][nx];
            q.push({ny, nx});
        }
    }
    printf("%d", visited[n - 1][m - 1] - 1);
    return 0;
}