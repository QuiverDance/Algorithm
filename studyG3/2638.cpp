/*
    #2638 치즈
*/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, m, a[104][104], visited[104][104], ret;
vector<pair<int, int>> v;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void checkAir(int y, int x){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(a[ny][nx] == 0 && visited[ny][nx] == 0){
            visited[ny][nx] = 1;
            checkAir(ny, nx);
        }
        if(a[ny][nx] > 0){
            visited[ny][nx]++;
            if(visited[ny][nx] == 2)
                v.push_back({ny, nx});
        }
    }
}

bool isEnd(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 1) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    visited[0][0] = 1;
    checkAir(0, 0);
    while(!isEnd()){
        ret++;
        for(auto pos : v)
            a[pos.first][pos.second] = 0;

        memset(visited, 0, sizeof(visited));
        v.clear();
        checkAir(0, 0);
    }
    cout << ret;
    return 0;
}