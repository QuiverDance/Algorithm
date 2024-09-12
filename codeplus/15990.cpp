#include<iostream>
#include<cstring>
using namespace std;

int t, n, dp[100004][4];
int solve(int num, int pre){
    int &ret = dp[num][pre];
    if(ret != 0) return ret;
    
    if(num == 0) return ret = 1;
    
    for(int i = 1; i <= 3; i++){
        if(i == pre || num - i < 0) continue;
        ret += solve(num - i, i);
        ret %= 1000000009;
    }
    return ret;
}
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        cout << solve(n, 0) << '\n';
    }
    return 0;
}