#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<tuple>

using namespace std;

#define INF 10000000

int r, c, ret = INF;
int board[1000][1000], jMove[1000][1000], fMove[1000][1000];
pair<int, int> start;
vector<pair<int,int>> fires;
string s;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main(void){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        cin >> s;
        for(int j = 0; j < c; j++){
            board[i][j] = s[j];
            if(s[j] == 'J') start = {i, j};
            if(s[j] == 'F') fires.push_back({i, j});
        }
    }

    queue<pair<int, int>> q;
    q.push(start); jMove[start.first][start.second] = 1;
    int y, x;
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny > r - 1 || nx > c - 1) continue;
            if(board[ny][nx] == '#' || jMove[ny][nx] > 0) continue;
            jMove[ny][nx] = jMove[y][x] + 1;
            q.push({ny, nx});
        }
    }

    for(pair<int,int> f : fires){
        q.push(f); fMove[f.first][f.second] = 1;
    }
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny > r - 1 || nx > c - 1) continue;
            if(board[ny][nx] == '#' || fMove[ny][nx] > 0) continue;
            fMove[ny][nx] = fMove[y][x] + 1;
            q.push({ny, nx});
        }
    }

    for(int i = 0; i < r; i++){
        if(jMove[i][0] > 0 && (fMove[i][0] == 0 || jMove[i][0] < fMove[i][0])) ret = min(ret, jMove[i][0]);
        if(jMove[i][c-1] > 0 && (fMove[i][c-1] == 0 || jMove[i][c-1] < fMove[i][c-1])) ret = min(ret, jMove[i][c-1]);
    }
    for(int i = 0; i < c; i++){
        if(jMove[0][i] > 0 && (fMove[0][i] == 0 || jMove[0][i] < fMove[0][i])) ret = min(ret, jMove[0][i]);
        if(jMove[r-1][i] > 0 && (fMove[r-1][i] == 0 || jMove[r-1][i] < fMove[r-1][i])) ret = min(ret, jMove[r-1][i]);
    }
    if(ret == INF)
        cout << "IMPOSSIBLE\n";
    else cout << ret << '\n';
    return 0;
}