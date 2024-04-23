/*
    #7569 토마토
*/
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int n, m, h, ret, a[104][104][104], visited[104][104][104];
queue<tuple<int, int, int>> q;
int dy[] = {1, 0, -1, 0, 0, 0};
int dx[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> h;
    for(int k = 0; k < h; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j][k];
                if(a[i][j][k] == 1){
                    visited[i][j][k] = 1;
                    q.push(make_tuple(i, j, k));
                }
            }
        }
    }

    int y, x, z;
    while(!q.empty()){
        tie(y, x, z) = q.front(); q.pop();
        for(int i = 0; i < 6; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nz = z + dz[i];
            if(ny < 0 || nx < 0 || nz < 0 || ny >= n || nx >= m || nz >= h) continue;
            if(visited[ny][nx][nz] || a[ny][nx][nz] == -1) continue;
            visited[ny][nx][nz] = visited[y][x][z] + 1;
            q.push(make_tuple(ny, nx, nz));
            ret = max(ret, visited[ny][nx][nz]);
        }
    }

    for(int k = 0; k < h; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j][k] == 0 && visited[i][j][k] == 0){
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    
    ret = (ret == 0 ? 0 : ret - 1);
    cout << ret;            
    return 0;
}