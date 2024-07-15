/*
    #16236 아기 상어
*/
#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;

int n, a[24][24], visited[24][24], sy, sx, s_size = 2, cnt, ret;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 9){
                sy = i; sx = j; a[i][j] = 0;
            }
        }
    }
    while(true){
        queue<pair<int, int>> q;
        vector<pair<int, pair<int, int>>> v;
        memset(visited, 0, sizeof(visited));

        q.push({sy, sx}); visited[sy][sx] = 1;
        int y, x;
        while(!q.empty()){
            tie(y, x) = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i], nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                if(visited[ny][nx] || a[ny][nx] > s_size) continue;
                q.push({ny, nx}); visited[ny][nx] = visited[y][x] + 1;
                if(a[ny][nx] > 0 && a[ny][nx] < s_size)
                    v.push_back({visited[ny][nx], {ny, nx}});
            }
        }
        if(v.empty()) break;
        sort(v.begin(), v.end());
        ret += v[0].first - 1, cnt++;
        y = v[0].second.first; x = v[0].second.second;
        a[y][x] = 0;
        sy = y; sx = x;
        if(cnt == s_size){
            s_size++; cnt = 0;
        }
    }
    cout << ret;
    return 0;
}