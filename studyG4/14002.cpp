/*
    #14002 가장 긴 증가하는 부분 수열 4
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int n, a[1004], dp[1004], trace[1004], ret = 1;
vector<int> v;
int main(){
    memset(trace, -1, sizeof(trace));
    cin >> n;
    int num;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(a[i] <= a[j]) continue;
            if(dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                trace[i] = j;
                ret = max(ret, dp[i]);
            } 
        }
    }
    int cur;
    for(int i = 0; i < n; i++){
        if(dp[i] == ret){
            cur = i; break;
        }
    }
    
    cout << ret << '\n';
    while(true){
        v.push_back(a[cur]);
        cur = trace[cur];
        if(cur == -1) break;
    }
    reverse(v.begin(), v.end());
    for(int it : v) cout << it << " ";
    return 0;
}