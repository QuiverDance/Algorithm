/*
    #1926 그림
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, a[504][504], visited[504][504];
vector<int> v;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0 , -1};
int dfs(int y, int x){
    visited[y][x] = 1;
    int ret = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(visited[ny][nx]) continue;
        if(a[ny][nx] == 1) ret += dfs(ny, nx);
    }
    return ret;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 0 || visited[i][j]) continue;
            v.push_back(dfs(i, j));
        }
    }
    sort(v.begin(), v.end());
    if(v.size() == 0) cout << 0 << '\n' << 0;
    else
        cout << v.size() << '\n' << v[v.size() - 1];
    return 0;
}