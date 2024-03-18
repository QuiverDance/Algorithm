/*
 #2667 단지번호붙이기
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[29][29], visited[29][29];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> v;
int dfs(int y, int x, int label){
    visited[y][x] = label;
    int cnt = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
        if(a[ny][nx] == 1) cnt += dfs(ny, nx, label);
    }
    return cnt;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) scanf("%1d", &a[i][j]);
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] || a[i][j] == 0) continue;
            v.push_back(dfs(i, j, ++cnt));
        }
    }
    sort(v.begin(), v.end());
    printf("%ld\n", v.size());
    for(int it : v) printf("%d\n", it);
    return 0;
}