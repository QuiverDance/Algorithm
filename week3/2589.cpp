#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int n, m, ret = 0;
string s;
int board[50][50];
vector<pair<int, int>> landList;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int getMaxDistance(int visited[50][50]){
    int max = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(max < visited[i][j]) max = visited[i][j];
        }
    }
    return max;
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            board[i][j] = s[j];
            if(board[i][j] == 'L') landList.push_back({i, j});
        } 
    }

    for(int i = 0; i < landList.size(); i++){
        queue<pair<int,int>> q;
        int visited[50][50];
        fill(&visited[0][0], &visited[0][0] + 50*50, -1);
        q.push(landList[i]); visited[landList[i].first][landList[i].second] = 0;
        
        while(q.size()){
            pair<int, int> cur = q.front();
            q.pop();

            for(int d = 0; d < 4; d++){
                int ny = cur.first + dy[d];
                int nx = cur.second + dx[d];
                if(ny < 0 || nx < 0 || ny > n - 1 || nx > m - 1) continue;
                if(board[ny][nx] == 'W' || visited[ny][nx] >= 0) continue;
                visited[ny][nx] = visited[cur.first][cur.second] + 1;
                q.push({ny, nx});
            }
        }
        ret = max(ret, getMaxDistance(visited));
    }
    cout << ret;
    return 0;
}

