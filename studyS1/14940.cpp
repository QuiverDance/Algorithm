/*
    #14940 쉬운 최단거리
*/
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int n, m, a[1004][1004], visited[1004][1004], sy, sx;
queue<pair<int, int>> q;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int num;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> num; a[i][j] = num;
            if(num == 2){ sy = i; sx = j;}
        }
    }

    visited[sy][sx] = 1;
    q.push({sy, sx});
    int y, x;
    while(!q.empty()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visited[ny][nx] || a[ny][nx] == 0) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] > 0) cout << visited[i][j] - 1 << " ";
            else if(a[i][j] > 0) cout << -1 << " ";
            else cout << 0 << " ";
        }
        cout << '\n';
    }
    return 0;
}