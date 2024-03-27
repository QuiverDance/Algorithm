/*
    #2583 영역 구하기
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int m, n, k, a[104][104], visited[104][104], cnt;
int sx, sy, ex, ey;
vector<int> v;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int dfs(int y, int x){
    visited[y][x] = 1;
    int ret = 0;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx]) continue;
        if(a[ny][nx] == 0)
            ret += 1 + dfs(ny, nx);
    }
    return ret;
}

int main(){
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> sx >> sy >> ex >> ey;
        for(int i = sy; i < ey; i++){
            for(int j = sx; j < ex; j++) a[i][j] = 1;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 1 || visited[i][j]) continue;
            v.push_back(dfs(i, j) + 1);
            cnt++;
        }
    }
    sort(v.begin(), v.end());
    cout << cnt << '\n';
    for(int it : v) cout << it << " ";
    return 0;
}