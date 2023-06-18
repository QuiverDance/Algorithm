#include<iostream>
#include<vector>

#define visited 9;

using namespace std;

int n, m, board[10][10], temp[10][10], ret = 1e9;
vector<pair<int, int>> v;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

vector<pair<int, int>> extendCCTV(int idx, int dir){
    vector<pair<int, int>> modified;
    int y = v[idx].first;
    int x = v[idx].second;
    if(board[y][x] == 1){
        while(true){
            int ny = y + dy[dir]; 
            int nx = x + dx[dir]; 
            if(ny >= 0 && ny < n && nx >= 0 && nx < m && board[ny][nx] != 6){
                if(board[ny][nx] == 0){
                    board[ny][nx] = visited; 
                    modified.push_back({ny, nx});
                }
                y = ny; 
                x = nx; 
            }else break;
        }
    }else if(board[y][x] == 2){
        for(int i = 0; i <= 2; i +=2){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4]; 
                if(ny >= 0 && ny < n && nx >= 0 && nx < m && board[ny][nx] != 6){
                    if(board[ny][nx] == 0){board[ny][nx] = visited; modified.push_back({ny, nx});}
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }else if(board[y][x] == 3){
        for(int i = 0; i < 2; i++){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];
                if(ny >= 0 && ny < n && nx >= 0 && nx < m && board[ny][nx] != 6){
                    if(board[ny][nx] == 0){ board[ny][nx] = visited; modified.push_back({ny, nx});}
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }else if(board[y][x] == 4){
        for(int i = 0; i < 3; i++){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];
                if(ny >= 0 && ny < n && nx >= 0 && nx < m && board[ny][nx] != 6){
                    if(board[ny][nx] == 0){ board[ny][nx] = visited; modified.push_back({ny, nx});}
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }else if(board[y][x] == 5){
        for(int i = 0; i < 4; i++){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4]; 
                if(ny >= 0 && ny < n && nx >= 0 && nx < m && board[ny][nx] != 6){
                    if(board[ny][nx] == 0){ board[ny][nx] = 8; modified.push_back({ny, nx});}
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }
    return modified; 
}

void dfs(int idx){
    if(idx == v.size()){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 0) cnt++;
            }
        }
        ret = min(cnt, ret);
        return;
    }
    for(int d = 0; d < 4; d++){
        vector<pair<int, int>> modified = extendCCTV(idx, d);
        dfs(idx + 1);
        for(auto it : modified) board[it.first][it.second] = 0;
    }
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6) v.push_back({i, j});
        }
    }
    dfs(0);
    cout << ret;
    return 0;
}