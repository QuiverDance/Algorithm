#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int n, m;
int map[100][100];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int visited[100][100];
queue<pair<int, int>> q;
void bfs(){
    int y, x;
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny > n-1 || nx > m-1) continue;
            if(map[ny][nx] == 1 && visited[ny][nx] == 0){
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
    }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    string s;    
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++) map[i][j] = s[j] - '0';
    }
    visited[0][0] = 1; q.push({0, 0});
    bfs();

    cout << visited[n-1][m-1] << '\n';
    return 0;
}