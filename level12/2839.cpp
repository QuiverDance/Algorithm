#include<iostream>
using namespace std;
#define INF 2000

int n, dp[5004];
int solve(int sum){
    if(sum > n) return INF;
    if(sum == n) return 0;
    int& ret = dp[sum];
    if(ret != INF) return ret; 
    return ret = min(solve(sum + 3) + 1, solve(sum + 5) + 1);
}
int main(void){
    fill(&dp[0], &dp[0] + 5004, INF);
    cin >> n;
    int ret = solve(0);
    if(ret >= INF) cout << -1;
    else cout << ret;
    return 0;
}