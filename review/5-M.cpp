#include<iostream>
using namespace std;

int n, ret, a[24][24];

int* move(int board[24][24])[24]{
    for(int i = 0; i < n; i++){
        int pos = -1, flag = 0;
        for(int j = 0; j < n; j++){
            if(board[i][j] == 0) continue;
            if(flag == 1 && board[i][j] == board[i][pos]){
                flag = 0; board[i][pos] *= 2; 
            }
            else{
                flag = 1; board[i][++pos] = board[i][j];
            }
        }
        for(int j = pos + 1; j < n; j++) board[i][j] = 0;
    }
    return board;
}

void solve(int idx, int origin[24][24]){
    if(idx == 5){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ret = max(ret, origin[i][j]);
            }
        }
    }
    for(int i = 0; i < 4; i++){
        int temp[24][24] = move(origin);
        solve(idx + 1, rotate(temp));
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    solve(0, a);
    cout << ret;
    return 0;
}