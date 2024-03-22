/*
    #1992 쿼드트리
*/
#include<iostream>
#include<string>
using namespace std;

int n, a[68][68];
string s;
bool isFilled(int y, int x, int size){
    int val = a[y][x];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(val != a[y + i][x + j]) return false;
        }
    }
    return true;
}

void solve(int y, int x, int size){
    if(isFilled(y, x, size)){
        cout << a[y][x]; return;
    }
    cout << '(';
    int half = size / 2;
    solve(y, x, half);
    solve(y, x + half, half);
    solve(y + half, x, half);
    solve(y + half, x + half, half);
    cout << ')';
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < n; j++) a[i][j] = s[j] - '0';
    }
    solve(0, 0, n);
    return 0;
}