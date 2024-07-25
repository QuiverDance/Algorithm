/*
    #15683 감시
*/
#include<iostream>
#include<vector>

#define visited 9;

using namespace std;

int n, m, a[10][10], temp[10][10], ret = 1e9;
vector<pair<int, int>> v;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

vector<pair<int, int>> detect(int idx, int dir){
    vector<pair<int, int>> detected;
    int y = v[idx].first;
    int x = v[idx].second;
    if(a[y][x] == 1){
        while(true){
            int ny = y + dy[dir]; 
            int nx = x + dx[dir]; 
            if(ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6){
                if(a[ny][nx] == 0){
                    a[ny][nx] = visited; 
                    detected.push_back({ny, nx});
                }
                y = ny; 
                x = nx; 
            }else break;
        }
    }else if(a[y][x] == 2){
        for(int i = 0; i <= 2; i +=2){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4]; 
                if(ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6){
                    if(a[ny][nx] == 0){a[ny][nx] = visited; detected.push_back({ny, nx});}
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }else if(a[y][x] == 3){
        for(int i = 0; i < 2; i++){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];
                if(ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6){
                    if(a[ny][nx] == 0){ a[ny][nx] = visited; detected.push_back({ny, nx});}
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }else if(a[y][x] == 4){
        for(int i = 0; i < 3; i++){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];
                if(ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6){
                    if(a[ny][nx] == 0){ a[ny][nx] = visited; detected.push_back({ny, nx});}
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }else if(a[y][x] == 5){
        for(int i = 0; i < 4; i++){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4]; 
                if(ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6){
                    if(a[ny][nx] == 0){ a[ny][nx] = 8; detected.push_back({ny, nx});}
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }
    return detected; 
}

void solve(int idx){
    if(idx == v.size()){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 0) cnt++;
            }
        }
        ret = min(cnt, ret);
        return;
    }
    for(int d = 0; d < 4; d++){
        vector<pair<int, int>> detected = detect(idx, d);
        solve(idx + 1);
        for(auto it : detected) a[it.first][it.second] = 0;
    }
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] != 0 && a[i][j] != 6) v.push_back({i, j});
        }
    }
    solve(0);
    cout << ret;
    return 0;
}