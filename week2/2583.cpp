#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int m, n, k, a, b, c, d, cnt = 0, area = 0;
int map[100][100], visited[100][100];
vector<int> areaVector;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    visited[y][x] = 1;
    area++;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny > m - 1 || nx > n - 1) continue;
        if(map[ny][nx] == 0 && !visited[ny][nx])
            dfs(ny, nx);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> a >> b >> c >> d;
        for(int y = b; y < d; y++){
            for(int x = a; x < c; x++){
                map[y][x] = 1;
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 0 && !visited[i][j]){
                cnt++;
                dfs(i, j);
                areaVector.push_back(area);
                area = 0;
            }
        }
    }
    sort(areaVector.begin(), areaVector.end());
    cout << cnt << '\n';
    for(int i : areaVector)
        cout << i << " ";
    return 0;
}