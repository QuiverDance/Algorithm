/*
    #2448 별 찍기 - 11
*/
#include<iostream>
using namespace std;

int n;
char ret[4000][8000];
void solve(int sy, int sx, int size){
    if(size == 3){
        for(int i = 0; i < 5; i++) ret[sy][sx + i] = '*';
        ret[sy + 1][sx + 1] = '*'; ret[sy + 1][sx + 3] = '*';
        ret[sy + 2][sx + 2] = '*';
        return;
    }
    solve(sy, sx, size / 2);
    solve(sy, sx + size, size / 2);
    solve(sy + size / 2, sx + size / 2, size / 2);
}
int main(){
    cin >> n;
    solve(0, 0, n);
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < 2 * n; j++){
            if(ret[i][j] == 0) cout << " ";
            else cout << ret[i][j];
        }
        cout << '\n';
    }
}