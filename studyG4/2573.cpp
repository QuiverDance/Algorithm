/*
    #2573 빙산
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<tuple>
using namespace std;

int n, m, a[304][304], ret, visited[304][304], cnt;
vector<pair<int, int>> v;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i], nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(a[ny][nx] == 0 || visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

bool check(){
    memset(visited, 0, sizeof(visited));
    int y, x;
    cnt = 0;
    for(auto pos : v){
        y = pos.first; x = pos.second;
        if(a[y][x] == 0 || visited[y][x]) continue;
        cnt++;
        dfs(y, x);
    }
    return cnt >= 2 || cnt == 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] > 0) v.push_back({i, j});
        }
    }

    int y, x;
    while(!check()){
        ret++;
        vector<pair<pair<int, int>, int>> temp;
        for(auto pos : v){
            y = pos.first; x = pos.second;
            if(a[y][x] == 0) continue;
            int w = 0;
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i], nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(a[ny][nx] == 0) w++;
            }
            temp.push_back({{y, x}, w});
        }
        for(auto it: temp){
            tie(y, x) = it.first;
            a[y][x] = max(0, a[y][x] - it.second);
        }
    }
    cout << (cnt == 0 ? 0 : ret);
    return 0;
}