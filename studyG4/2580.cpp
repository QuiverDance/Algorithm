/*
    #2580 스토쿠
*/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int a[9][9], n;
vector<pair<int, int>> v;
bool isValid(int y, int x){
    for(int i = 0; i < 9; i++){
        if(i != y && a[y][x] == a[i][x]) return false;
        if(i != x && a[y][x] == a[y][i]) return false;
    }

    int sy = (y / 3) * 3;
    int sx = (x / 3) * 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(sy + i != y && sx + j != x && a[y][x] == a[sy + i][sx + j]) return false;
        }
    }
    return true;
}

void solve(int idx){
    if(idx == n){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++) cout << a[i][j] << " ";
            cout << '\n';
        }
        exit(0);
    }
    int y = v[idx].first, x = v[idx].second;
    for(int i = 1; i <= 9; i++){
        a[y][x] = i;
        if(isValid(y, x))
            solve(idx + 1);
    }
    a[y][x] = 0;
}

int main(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> a[i][j];
            if(a[i][j] == 0){
                v.push_back({i, j});
                n++;
            }
        }
    }
    solve(0);
    return 0;
}