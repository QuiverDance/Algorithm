/*
    #16234 인구 이동
*/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, l, r, a[54][54], ret, visited[54][54], flag;
vector<pair<int, int>> v;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int dfs(int y, int x){
    visited[y][x] = 1; v.push_back({y, x});
    int sum = a[y][x];
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
        if(abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r)
            sum += dfs(ny, nx);
    }
    return sum;
}

int main(){
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }

    while(true){
        memset(visited, 0, sizeof(visited)); flag = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j]) continue;
                v.clear();
                int sum = dfs(i, j);
                if(v.size() == 1) continue; 
                for(auto pos : v){
                    a[pos.first][pos.second] = sum / v.size();
                }
                flag = 1;
            }
        }
        if(flag) ret++;
        else break;
    }
    cout << ret;
    return 0;
}