/*
    #2447 별 찍기 - 10
*/
#include<iostream>
using namespace std;

int n;
char a[10004][10004];
void solve(int y, int x, int size, int val){
    if(size == 1 && val == 1){
        a[y][x] = '*'; return;
    }
    if(val == 0){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++)
                a[y + i][x + j] = ' ';
        }
        return;
    }
    int third = size / 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == 1 && j == 1) solve(y + i * third, x + j * third, third, 0);
            else solve(y + i * third, x + j * third, third, 1);
        }
    }
}
int main() {
    cin >> n;
    solve(0, 0, n, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << a[i][j];
        cout << '\n';
    }
    return 0;
}