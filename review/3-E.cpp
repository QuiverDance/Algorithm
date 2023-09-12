#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int n, visited[64][64][64], a[3];
int d[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9},
};
queue<tuple<int, int, int>> q;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    q.push(make_tuple(a[0], a[1], a[2]));
    visited[a[0]][a[1]][a[2]] = 1;
    int x, y, z;
    while(!q.empty()){
        tie(x, y, z) = q.front();
        q.pop();
        for(int i = 0; i < 6; i++){
            int nx = max(0, x - d[i][0]);
            int ny = max(0, y - d[i][1]);
            int nz = max(0, z - d[i][2]);
            if(visited[nx][ny][nz]) continue;
            visited[nx][ny][nz] = visited[x][y][z] + 1;
            q.push(make_tuple(nx, ny, nz));
        }
    }
    cout << visited[0][0][0] - 1;
    return 0;
}