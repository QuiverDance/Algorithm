/*
    #4179 불!
*/
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int n, m, jvisited[1004][1004], fvisited[1004][1004], ret = 1e9;
char a[1004][1004];
queue<pair<int, int>> jq, fq;
vector<pair<int, int>> v;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'J'){
                jvisited[i][j] = 1;
                jq.push({i, j});
            }
            if(a[i][j] == 'F'){
                fvisited[i][j] = 1;
                fq.push({i, j});
            }
            if((a[i][j] == '.' || a[i][j] == 'J') && (i == 0 || i == n - 1 || j == 0 || j == m - 1))
                v.push_back({i, j});
        }
    }

    int y, x;
    while(!fq.empty()){
        tie(y, x) = fq.front(); fq.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(a[ny][nx] == '#' || fvisited[ny][nx]) continue;
            fvisited[ny][nx] = fvisited[y][x] + 1;
            fq.push({ny, nx});
        }
    }
    while(!jq.empty()){
        tie(y, x) = jq.front(); jq.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(a[ny][nx] == '#' || jvisited[ny][nx]) continue;
            if(fvisited[ny][nx] && jvisited[y][x] + 1 >= fvisited[ny][nx]) continue;
            jvisited[ny][nx] = jvisited[y][x] + 1;
            jq.push({ny, nx});
        }
    }

    for(auto pos : v){
        if(jvisited[pos.first][pos.second])
            ret = min(ret, jvisited[pos.first][pos.second]);
    }
    if(ret == 1e9) cout << "IMPOSSIBLE";
    else cout << ret;
}