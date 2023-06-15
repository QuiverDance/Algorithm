#include<iostream>

using namespace std;

int n, ret1 = -1e9, ret2 = 1e9;
int num[15];

int cal(int a, int b, int o){
    switch (o)
    {
    case 0:
        return a + b;
        break;
    case 1:
        return a - b;
        break;
    case 2:
        return a * b;
        break;
    case 3:
        return a / b;
        break;        
    default:
        break;
    }
}

void solve(int idx, int op[4], int result){
    if(idx == n){
        ret1 = max(ret1, result);
        ret2 = min(ret2, result);
        return;
    }
    int value = 0;
    for(int i = 0; i < 4; i++){
        if(op[i] < 1) continue;
        op[i]--;
        solve(idx + 1, op, cal(result, num[idx], i));
        op[i]++;
    }
}

int main(void){
    cin >> n;
    int op[4];
    for(int i = 0; i < n; i++) cin >> num[i];
    for(int i = 0; i < 4; i++) cin >> op[i];

    solve(1, op, num[0]);
    cout << ret1 << '\n' << ret2;
    return 0;
}