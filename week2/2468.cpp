#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, a, maxh = 0, cnt, ret = 0;
int m[100][100], visited[100][100];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> safe;

void dfs(int y, int x, int h){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny > n-1 || nx > n-1) continue;
        if(m[ny][nx] > h && visited[ny][nx] == 0)
            dfs(ny, nx, h);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a;
            m[i][j] = a;
            if(maxh < a) maxh = a;
        }
    }
    
    for(int h = 0; h < maxh; h++){
        cnt = 0;
        fill(&visited[0][0], &visited[0][0] + 100*100, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(m[i][j] > h && visited[i][j] == 0){
                    cnt++;
                    dfs(i, j, h);
                }
            }
        }
        ret = max(ret, cnt);
    }
    cout << ret;
    return 0;   
}