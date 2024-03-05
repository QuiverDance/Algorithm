/*
    #1780 종이의 개수
*/
#include<iostream>
using namespace std;

int n, ret[3], a[3000][3000];
bool isFilled(int sx, int sy, int size){
    int flag = 1;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(a[sy][sx] != a[sy + i][sx + j]){
                flag = 0; 
                break;
            }
        }
    }
    return flag == 1;
}

void solve(int sx, int sy, int size){
    if(isFilled(sx, sy, size)){
        ret[a[sy][sx] + 1]++;
        return;
    }
    solve(sx, sy, size / 3);
    solve(sx + size / 3, sy, size / 3);
    solve(sx + 2 * size / 3, sy, size / 3);
    solve(sx, sy + size / 3, size / 3);
    solve(sx + size / 3, sy + size / 3 , size / 3);
    solve(sx + 2 * size / 3, sy + size / 3, size / 3);
    solve(sx, sy + 2 * size / 3, size / 3);
    solve(sx + size / 3, sy + 2 * size / 3, size / 3);
    solve(sx + 2 * size / 3, sy + 2 * size / 3, size / 3);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    solve(0, 0, n);
    cout << ret[0] << '\n' << ret[1] << '\n' << ret[2];
    return 0;
}