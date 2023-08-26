#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, m, cnt, ret, a[104][104], visited[104][104];
vector<pair<int, int>> v;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        if(a[ny][nx] == 0) dfs(ny, nx);
        else{
            visited[ny][nx] = 1;
            a[ny][nx] = 0;
            v.push_back({ny, nx});
        }
    }

}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    while(true){
        memset(visited, 0, sizeof(visited));
        v.clear();
        dfs(0, 0);
        if(v.size()) ret = v.size();
        else break;
        cnt++;
    }
    cout << cnt << '\n' << ret;
    return 0;
}