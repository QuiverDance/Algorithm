/*
    #7562 나이트의 이동
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<tuple>
using namespace std;

int t, n, visited[304][304], sy, sx, ey, ex;
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    while(t--){
        memset(&visited[0][0], 0, sizeof(visited));
        cin >> n >> sy >> sx >> ey >> ex;
        queue<pair<int, int>> q;
        q.push({sy, sx}); visited[sy][sx] = 1;
        int y, x;
        while(!q.empty()){
            tie(y, x) = q.front(); q.pop();
            for(int i = 0; i < 8; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                if(visited[ny][nx]) continue;
                q.push({ny, nx}); visited[ny][nx] = visited[y][x] + 1;
            }
        }
        cout << visited[ey][ex] - 1 << '\n';
    }
    return 0;
}