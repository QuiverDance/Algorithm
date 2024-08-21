/*
    #17142 연구소 3
*/
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;

int n, m, a[54][54], temp[54][54], v_cnt, visited[54][54], ret = 1e9;
vector<pair<int, int>> virus;
vector<vector<int>> s_virus;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void combi(int idx, vector<int> b){
    if(b.size() == m){
        s_virus.push_back(b);
        return;
    }
    for(int i = idx; i < v_cnt; i++){
        b.push_back(i);
        combi(i + 1, b);
        b.pop_back();
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 2){
                virus.push_back({i, j});
                v_cnt++;
            }
        }
    }
    vector<int> b;
    combi(0, b);
    for(vector<int> v : s_virus){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) temp[i][j] = a[i][j];
        }
        memset(visited, 0, sizeof(visited));
        queue<pair<int, int>> q;
        for(int it : v){
            q.push({virus[it].first, virus[it].second});
            visited[virus[it].first][virus[it].second] = 1;
            temp[virus[it].first][virus[it].second] = 3; 
        }
        int y, x;
        while(!q.empty()){
            tie(y, x) = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                if(visited[ny][nx] || temp[ny][nx] == 1) continue;
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny,nx});
            }
        }
        int cnt = 0, flag = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(temp[i][j] == 1 || temp[i][j] == 2) continue;
                if(visited[i][j] == 0) flag = 1;
                else cnt = max(cnt, visited[i][j]);
            }
        }
        if(flag == 0) ret = min(ret, cnt - 1);
    }
    if(ret == 1e9) cout << -1;
    else cout << ret;
    return 0;
}