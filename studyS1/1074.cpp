/*
    #1074 Z
*/
#include<iostream>
#include<cmath>
using namespace std;

int n, r, c;
void solve(int y, int x, int size, int sval){
    if(y == r && x == c){
        cout << sval; return;
    }
    int half = size / 2;
    if(r < y + half && c < x + half){ //left up
         solve(y, x, half, sval);
    }
    else if(r < y + half && c >= x + half){ //right up
        solve(y, x + half, half, sval + (int)pow(half, 2));
    }
    else if(r >= y + half && c < x + half){ //left down
        solve(y + half, x, half, sval + (int)pow(half, 2) * 2);
    }
    else{ //right down
        solve(y + half, x + half, half, sval + (int)pow(half, 2) * 3);
    }
}

int main(){
    cin >> n >> r >> c;
    solve(0, 0, (int)pow(2, n), 0);
    return 0;
}