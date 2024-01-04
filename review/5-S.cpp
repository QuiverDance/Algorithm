#include<iostream>
using namespace std;

int n, oprand[12], a[4], mx = -1e9, mn = 1e9; 
int cal(int opr1, int opr2, int op){
    if(op == 0) return opr1 + opr2;
    if(op == 1) return opr1 - opr2;
    if(op == 2) return opr1 * opr2;
    return opr1 / opr2;
}

void solve(int idx, int result){
    if(idx == n){
        mx = max(mx, result);
        mn = min(mn, result);
        return;
    }
    for(int i = 0; i < 4; i++){
        if(a[i] > 0){
            a[i]--;
            solve(idx + 1, cal(result, oprand[idx], i));
            a[i]++;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> oprand[i];
    for(int i = 0; i < 4; i++) cin >> a[i];
    solve(1, oprand[0]);
    cout << mx << '\n' << mn;
    return 0;
}