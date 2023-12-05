#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<tuple>
using namespace std;

int r, c, t, ret;
int a[54][54], temp[54][54];
vector<pair<int, int>> v1, v2;
int dy1[] = {0, -1, 0, 1};
int dx1[] = {1, 0, -1, 0};
int dy2[] = {0, 1, 0, -1};
int dx2[] = {1, 0, -1, 0};

void spread(){
    memset(temp, 0, sizeof(temp));
    queue<pair<int, int>> q;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(a[i][j] > 0) q.push({i, j});
        }
    }
    int y, x;
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        int amount = a[y][x] / 5;
        for(int i = 0; i < 4; i++){
            int ny = y + dy1[i];
            int nx = x + dx1[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c || a[ny][nx] == -1) continue;
            temp[ny][nx] += amount;
            a[y][x] -= amount;
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            a[i][j] += temp[i][j];
        }
    }
}

vector<pair<int, int>> makeSection(int sy, int sx, int dy[], int dx[]){
    vector<pair<int, int>> section;
    int y = sy, x = sx, d = 0;
    while(true){
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c){
            d++;
            ny = y + dy[d];
            nx = x + dx[d];
        }
        if(ny == sy && nx == sx) break;
        section.push_back({ny, nx});
        y = ny; x = nx;
    }
    return section;
}

void work(vector<pair<int, int>> section){
    for(int i = section.size() - 1; i > 0; i--)
        a[section[i].first][section[i].second] = a[section[i - 1].first][section[i - 1].second];
    a[section[0].first][section[0].second] = 0; 
}

int main(){
    cin >> r >> c >> t;
    int flag = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
            if(!flag && a[i][j] == -1) { v1 = makeSection(i, j, dy1, dx1); flag = 1; }
            else if(flag && a[i][j] == -1) v2 = makeSection(i, j, dy2, dx2);
        }
    }

    while(t--){
        spread();
        work(v1);
        work(v2);
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(a[i][j] > 0) ret += a[i][j];
        }
    }
    cout << ret;
    return 0;
}