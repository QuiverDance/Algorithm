/*
    #14442번 벽 부수고 이동하기 2
*/
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int n, m, k, a[1004][1004], visited[1004][1004][14], sy, sx, ret = 1e9;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
queue<pair<pair<int, int>, int>> q;
void bfs(){
    q.push({{sy, sx}, 0}); visited[sy][sx][0] = 1;
    int y, x, cnt;
    while(!q.empty()){
        tie(y, x) = q.front().first; 
        cnt = q.front().second; q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(a[ny][nx] == 1 && cnt == k) continue;
            int ncnt = (a[ny][nx] == 0 ? cnt : cnt + 1);
            if(visited[ny][nx][ncnt]) continue;

            visited[ny][nx][ncnt] = visited[y][x][cnt] + 1;
            q.push({{ny, nx}, ncnt});
        }
    }
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) scanf("%1d", &a[i][j]);
    }

    bfs();
    
    for(int i = 0; i <= k; i++){
        if(visited[n - 1][m - 1][i]) ret = min(ret, visited[n - 1][m - 1][i]);
    }
    if(ret == 1e9) printf("-1");
    else printf("%d", ret);
    return 0;
}