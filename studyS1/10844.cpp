/*
    #10844 쉬운 계단 수
*/
#include<iostream>
#define DIV 1000000000
#define ll long long
using namespace std;

ll n, dp[10][104], ret;
ll solve(int idx, int num){
    if(idx == n) return 1;
    ll &rt = dp[num][idx];
    if(rt > 0) return rt;
    
    if(num == 0) rt = solve(idx + 1, num + 1) % DIV;
    else if(num == 9) rt = solve(idx + 1, num - 1) % DIV;
    else rt = (solve(idx + 1, num + 1) % DIV + solve(idx + 1, num - 1) % DIV) % DIV;
    return rt;
}

int main(){
    cin >> n;
    for(int i = 1; i <= 9; i++)
        ret += solve(1, i) % DIV;
    cout << ret % DIV;
    return 0;
}