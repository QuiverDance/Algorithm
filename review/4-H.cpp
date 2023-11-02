#include<iostream>
#include<vector>
using namespace std;

int n, m, a[51][51], visited[51][51], cnt = 0, ret1 = 0, ret2 = 0;
vector<int> room_size;
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

int dfs(int y, int x, int t){
    visited[y][x] = t;
    int ret = 1;
    for(int i = 0; i < 4; i++){
        if(!(a[y][x] & (1 << i))){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
            ret += dfs(ny, nx, t);
        }
    }
    return ret;
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j]) continue;
            cnt++;
            int area = dfs(i, j, cnt);
            ret1 = max(ret1, area);
            room_size.push_back(area);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i + 1 < n){
                int a = visited[i][j]; int b = visited[i + 1][j];
                if(a != b) ret2 = max(ret2, room_size[a - 1] + room_size[b - 1]); 
            }
            if(j + 1 < m){
                int a = visited[i][j]; int b = visited[i][j + 1];
                if(a != b) ret2 = max(ret2, room_size[a - 1] + room_size[b - 1]);
            }
        }
    }
    cout << cnt << '\n' << ret1 << '\n' << ret2;
    return 0;
}