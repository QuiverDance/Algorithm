/*
    #9663 N-Queen
*/
#include<iostream>
#include<vector>
using namespace std;

int n, ret, a[19];
bool check(int y, int x){
    for(int i = 0; i < y; i++){
        if(x == a[i] || y - i == abs(x - a[i])) return false;
    }
    return true;
}

void solve(int idx){
    if(idx == n){ ret++; return;}
    for(int i = 0; i < n; i++){
        a[idx] = i;
        if(check(idx, i))
            solve(idx + 1);
    }
}

int main(){
    cin >> n;
    solve(0);
    cout << ret;
    return 0;
}