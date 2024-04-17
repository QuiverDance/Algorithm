/*
    #7576 토마토
*/
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int n, m, a[1004][1004], visited[1004][1004], ret;
queue<pair<int, int>> q;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 1){ q.push({i, j}); visited[i][j] = 1; }
        }
    }

    int y, x;
    while(!q.empty()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visited[ny][nx] || a[ny][nx] == -1) continue;
            q.push({ny, nx}); visited[ny][nx] = visited[y][x] + 1;
            ret = max(ret, visited[ny][nx]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] != -1 && visited[i][j] == 0){
                cout << -1; return 0;
            }
        }
    }
    ret = (ret == 0 ? 0 : ret - 1);
    cout << ret;
    return 0;
}