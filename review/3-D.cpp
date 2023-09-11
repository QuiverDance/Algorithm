#include<iostream>
#include<string>
#include<queue>
#include<tuple>
using namespace std;

int r, c, a[1004][1004], f_visited[1004][1004], j_visited[1004][1004], ret = 1e8;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> f_q, j_q;
string s;
int main(){
    cin >> r >> c;

    for(int i = 0; i < r; i++){
        cin >> s;
        for(int j = 0; j < c; j++){
            a[i][j] = s[j];
            if(a[i][j] == 'F') {f_q.push({i, j}); f_visited[i][j] = 1;}
            if(a[i][j] == 'J') {j_q.push({i, j}); j_visited[i][j] = 1;}
        }
    }
    
    int y, x;
    while(!f_q.empty()){
        tie(y, x) = f_q.front();
        f_q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c || f_visited[ny][nx]) continue;
            if(a[ny][nx] != '#'){
                f_visited[ny][nx] = f_visited[y][x] + 1;
                f_q.push({ny, nx});
            }
        }
    }
    while(!j_q.empty()){
        tie(y, x) = j_q.front();
        j_q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c || j_visited[ny][nx]) continue;
            if(a[ny][nx] != '#'){
                j_visited[ny][nx] = j_visited[y][x] + 1;
                j_q.push({ny, nx});
            }
        }
    }

    for(int i = 0; i < c; i++){
        if(j_visited[0][i] && (j_visited[0][i] < f_visited[0][i] || f_visited[0][i] == 0)) ret = min(ret, j_visited[0][i]);
        if(j_visited[r - 1][i] && (j_visited[r - 1][i] < f_visited[r - 1][i] || f_visited[r - 1][i] == 0)) ret = min(ret, j_visited[r - 1][i]);
    }
    for(int i = 0; i < r; i++){
        if(j_visited[i][0] && (j_visited[i][0] < f_visited[i][0] || f_visited[i][0] == 0))  ret = min(ret, j_visited[i][0]);
        if(j_visited[i][c - 1] && (j_visited[i][c - 1] < f_visited[i][c - 1] || f_visited[i][c - 1] == 0)) ret = min(ret, j_visited[i][c - 1]);
    }
    if(ret == 1e8) cout << "IMPOSSIBLE\n";
    else cout << ret << '\n';
    return 0;
}