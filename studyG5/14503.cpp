/*
    #14503 로봇 청소기
*/
#include<iostream>
using namespace std;

int n, m, a[54][54], ret, r, c, d;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int main(){
    cin >> n >> m >> r >> c >> d;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }

    while(true){
        if(a[r][c] == 0){
            a[r][c] = 2; ret++;
        }
        
        int flag = 0;
        for(int i = 0; i < 4; i++){
            int ny = r + dy[i];
            int nx = c + dx[i];
            if(a[ny][nx] == 0){ flag = 1; break; }
        }
        if(flag == 0){
            int ny = r - dy[d];
            int nx = c - dx[d];
            if(a[ny][nx] == 1) break;
            r = ny; c = nx;
        }
        else{
            int ny, nx;
            do{
                d = (d + 3) % 4;
                ny = r + dy[d];
                nx = c + dx[d];
                if(a[ny][nx] == 1) continue;
            }while(a[ny][nx] != 0);
            r = ny; c = nx;
        }
    }
    cout << ret;
    return 0;
}