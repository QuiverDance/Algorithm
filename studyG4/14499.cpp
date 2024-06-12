/*
    #14499 주사위 굴리기
*/
#include<iostream>
using namespace std;

int n, m, x, y, k, a[24][24], dice[6];
int d, t, f, r, _top, _front, _right;
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};
int main(){
    cin >> n >> m >> y >> x >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    t = 0; f = 1; r = 2;
    while(k--){
        cin >> d; d--;
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        _top = t; _front = f; _right = r;
        if(d == 0){
            t = 5 - _right; r = _top;
        }
        else if(d == 1){
            t = _right; r = 5 - _top;
        }
        else if(d == 2){
            t = _front; f = 5 - _top;
        }
        else{
            t = 5 - _front; f = _top;
        }
        if(a[ny][nx] == 0) a[ny][nx] = dice[5 - t];
        else{
            dice[5 - t] = a[ny][nx]; a[ny][nx] = 0;
        }
        y = ny; x = nx;
        
        cout << dice[t] << '\n';
    }
    return 0;
}