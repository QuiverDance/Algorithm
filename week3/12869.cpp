#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

int n;
int vistied[61][61][61];
queue<tuple<int, int, int>> q;
int hp[3];
int d[6][3] = {
    {-9, -3, -1},
    {-9, -1, -3},
    {-3, -9, -1},
    {-3, -1, -9},
    {-1, -9, -3},
    {-1, -3, -9}
};

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> hp[i];
    }
    q.push({hp[0], hp[1], hp[2]});
    vistied[hp[0]][hp[1]][hp[2]] = 1;

    int x, y, z;
    while(q.size()){
        tie(x, y, z) = q.front();
        q.pop();
        for(int i = 0; i < 6; i++){
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            int nz = z + d[i][2];
            if(nx < 0) nx = 0;
            if(ny < 0) ny = 0;
            if(nz < 0) nz = 0;

            if(vistied[nx][ny][nz]) continue;
            vistied[nx][ny][nz] = vistied[x][y][z] + 1;
            q.push({nx, ny, nz});
        }
    }
    cout << vistied[0][0][0] - 1;
    return 0;
}