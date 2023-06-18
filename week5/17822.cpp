#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n, m, T, x, d, k, board[54][54], visited[54][54], ret, y;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool flag = 1;

void _rotate(int y, int dir, int k){
    vector<int> v;
    for(int i = 0; i < m; i++) v.push_back(board[y][i]);
    if(dir == 1)
        rotate(v.begin(), v.begin() + k, v.end());
    else
        rotate(v.begin(), v.begin() + m - k, v.end());
    for(int i = 0; i < m; i++)
        board[y][i] = v[i];
}

void dfs(int y, int x){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = (x + dx[i] + m) % m;
        if(ny < 0 || ny >= n) continue;
        if(visited[ny][nx]) continue;
        if(board[y][x] == board[ny][nx]){
            visited[y][x] = visited[ny][nx] = 1;
            flag = 0;
            dfs(ny, nx);
        }
    }
}

bool findAdj(){
    flag = 1;
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0) continue;
            if(visited[i][j]) continue;
            dfs(i, j);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j]) board[i][j] = 0;
        }
    }
    return flag;
}

void setAverage(){
    int sum = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0) continue;
            sum += board[i][j];
            cnt++;
        }
    }
    double avg = (double)sum / (double)cnt;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0) continue;
            if((double)board[i][j] > avg) board[i][j]--;
            else if((double)board[i][j] < avg) board[i][j]++;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> T;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < T; i++){
        cin >> x >> d >> k;
        for(int j = x - 1; j < n; j += x){
            _rotate(j, d, k);
        }
        if(findAdj()) setAverage();
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ret += board[i][j];
        }
    }
    cout << ret;
    return 0;
}