/*
    #말이 되고픈 원숭이
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<tuple>
using namespace std;

int k, n, m, a[204][204], visited[204][204][34], ret = 1e9;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int dy2[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dx2[] = {-2, -1, 1, 2, 2, 1, -1, -2};
queue<pair<pair<int, int>, int>> q;
int main(){
    cin >> k >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    q.push({{0, 0}, k}); visited[0][0][k] = 1;
    int y, x, cnt;
    while(!q.empty()){
        tie(y, x) = q.front().first;
        cnt = q.front().second;
        q.pop();
        if(cnt > 0){
            for(int i = 0; i < 8; i++){
                int ny = y + dy2[i];
                int nx = x + dx2[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(a[ny][nx] == 1 || visited[ny][nx][cnt - 1]) continue;
                visited[ny][nx][cnt - 1] = visited[y][x][cnt] + 1;
                q.push({{ny, nx}, cnt - 1});
            }
        }
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(a[ny][nx] == 1 || visited[ny][nx][cnt]) continue;
            visited[ny][nx][cnt] = visited[y][x][cnt] + 1;
            q.push({{ny, nx}, cnt});
        }
    }
    
    for(int i = 0; i <= k; i++){
        if(visited[n - 1][m - 1][i])
            ret = min(ret, visited[n - 1][m - 1][i]);
    }
    cout << (ret == 1e9 ? -1 : ret - 1);
    return 0;
}