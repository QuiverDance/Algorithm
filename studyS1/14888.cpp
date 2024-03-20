/*
    #14888 연산자 끼워넣기
*/
#include<iostream>
using namespace std;

int n, a[104], op[4], mx = -1e9, mn = 1e9;
int cal(int num1, int num2, int o){
    if(o == 0) return num1 + num2;
    else if(o == 1) return num1 - num2;
    else if(o == 2) return num1 * num2;
    else return num1 / num2;
}

void solve(int idx, int sum){
    if(idx == n){
        mx = max(mx, sum); mn = min(mn, sum);
        return;
    }
    for(int i = 0; i < 4; i++){
        if(op[i] == 0) continue;
        op[i]--;
        solve(idx + 1, cal(sum, a[idx], i));
        op[i]++;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < 4; i++) cin >> op[i];

    solve(1, a[0]);
    cout << mx << '\n' << mn;
    return 0;
}