/*
    #14500 테트로미노
*/
#include<iostream>
#include<cstring>
using namespace std;

int n, m, a[504][504], ret, window[3][3], visited[3][3];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

void dfs(int y, int x, int y_size, int x_size){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= y_size || nx >= x_size) continue;
        if(visited[ny][nx] || window[ny][nx] == 0) continue;
        dfs(ny, nx, y_size, x_size);
    }
}

void getScore(int y_size, int x_size){
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    for(int i = 0; i < y_size; i++){
        for(int j = 0; j < x_size; j++){
            if(visited[i][j] || window[i][j] == 0) continue;
            cnt++;
            dfs(i, j, y_size, x_size);
        }
    }
    
    if(cnt != 1) return;
    int sum = 0;
    for(int y = 0; y <= n - y_size; y++){
        for(int x = 0; x <= m - x_size; x++){
            sum = 0;
            for(int i = 0; i < 6; i++){
                if(window[i / x_size][i % x_size] == 0) continue;
                sum += a[y + i / x_size][x + i % x_size];
            }
            ret = max(ret, sum);
        }
    }
}

int main() {
    fill(&window[0][0], &window[0][0] + 3 * 3, 1);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <m; j++) cin >> a[i][j];
    }

    int sum = 0;
    for(int y = 0; y <= n - 1; y++){
        for(int x = 0; x <= m - 4; x++){
            sum = 0;
            for(int i = 0; i < 4; i++) sum += a[y][x + i];
            ret = max(ret, sum);
        }
    }
    for(int y = 0; y <= n - 4; y++){
        for(int x = 0; x <= m - 1; x++){
            sum = 0;
            for(int i = 0; i < 4; i++) sum += a[y + i][x];
            ret = max(ret, sum);
        }
    }

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < i; j++){
            window[i / 3][i % 3] = 0; window[j / 3][j % 3] = 0;
            getScore(2, 3);
            window[i / 3][i % 3] = 1; window[j / 3][j % 3] = 1;

            window[i / 2][i % 2] = 0; window[j / 2][j % 2] = 0;
            getScore(3, 2);
            window[i / 2][i % 2] = 1; window[j / 2][j % 2] = 1;
        }
    }
    cout << ret;
    return 0;
}