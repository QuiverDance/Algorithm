#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<tuple>
using namespace std;

int r, c, t, ret;
int a[54][54], temp[54][54];
vector<int> v1, v2;
int dy1[] = {0, -1, 0, 1};
int dx1[] = {1, 0, -1, 0};
int dy2[] = {0, 1, 0, -1};
int dx2[] = {1, 0, -1, 0};

void spread(){
    memset(temp, 0, sizeof(0));
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
        for(int i = 0; i < 4; i++){
            int ny = y + dy1[i];
            int nx = x + dx1[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        }
    }
}

int main(){
    cin >> r >> c >> t;
    int flag = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
            if(!flag) v1 = makeSection(i, j, dy1, dx1);
            else v2 = makeSection(i, j, dy2, dx2);
        }
    }
    while(t--){
        spread();
        work(v1);
        work(v2);
    }
    cout << ret;
    return 0;
}