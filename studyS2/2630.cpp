/*
    #2630 색종이 만들기
*/
#include<iostream>
using namespace std;

int n, ret[2], a[128][128];
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
        ret[a[sy][sx]]++;
        return;
    }
    solve(sx, sy, size / 2);
    solve(sx + size / 2, sy, size / 2);
    solve(sx, sy + size / 2, size / 2);
    solve(sx + size / 2, sy + size / 2, size / 2);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    solve(0, 0, n);
    cout << ret[0] << '\n' << ret[1];
    return 0;
}