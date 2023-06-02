#include<iostream>
#include<vector>
#include<tuple>
#include<cstring>

using namespace std;

int n, board[10][10], bloom[10][10], ret = 3001;
vector<tuple<int, int,int>> posList;
vector<pair<int, int>> flowerList;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void combi(){
    for(int i = 0; i < 100; i++){
        for(int j = i + 1; j < 100; j++){
            for(int k = j + 1; k < 100; k++)
                posList.push_back({i, j, k});
        }
    }
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> board[i][j];
    }
    combi();
    pair<int, int> p[3];
    int x, y;
    for(tuple<int, int, int> pos : posList){
        flowerList.clear();
        memset(bloom, 0, sizeof(bloom));
        p[0] = {get<0>(pos) / 10, get<0>(pos) % 10};
        p[1] = {get<1>(pos) / 10, get<1>(pos) % 10};
        p[2] = {get<2>(pos) / 10, get<2>(pos) % 10};
        for(int j = 0; j < 3; j++){
            tie(x, y) = p[j];
            bloom[y][x] = 1;
            flowerList.push_back({y, x});
        }
        for(int j = 0; j < 3; j++){
            tie(x, y) = p[j];
            for(int d = 0; d < 4; d++){
                int ny = y + dy[d];
                int nx = x + dx[d];
                if(ny < 0 || nx < 0 || ny > n - 1 || nx > n - 1) continue;
                if(bloom[ny][nx]) continue;
                flowerList.push_back({ny, nx});
                bloom[ny][nx] = 1;
            }
        }
        if(flowerList.size() != 15) continue;
        int value = 0;
        for(pair<int, int> t : flowerList)
            value += board[t.first][t.second];
        ret = min(ret, value);
    }
    cout << ret;
    return 0;
}