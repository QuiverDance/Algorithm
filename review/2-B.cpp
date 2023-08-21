#include<iostream>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;

int t, m, n, k, x, y;
int a[50][50], visited[50][50];
int dy[4] = {-1 , 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        if(a[ny][nx] == 1)
            dfs(ny, nx);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        memset(a, 0, sizeof(a));
        memset(visited, 0, sizeof(visited));
        cin >> m >> n >> k;
        for(int i = 0; i < k; i++){
            cin >> x >> y;
            a[y][x] = 1;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 0 || visited[i][j]) continue;
                cnt++;
                dfs(i, j);
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}