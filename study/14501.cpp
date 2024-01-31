/*
    #14501 퇴사
*/
#include <iostream>
#include <vector>
using namespace std;

int n, dp[25];
vector<pair<int, int>> v;

int main() {
    cin >> n;
    int t, p;
    v.push_back({0, 0});
    for(int i = 0; i < n; i++){
        cin >> t >> p;
        v.push_back({t - 1, p});
    }
    for(int i = 1; i <= n; i++){
        dp[i + v[i].first] = max(dp[i + v[i].first], dp[i - 1] + v[i].second);
        for(int j = i + v[i].first; j <= n; j++){
            dp[j] = max(dp[j], dp[i + v[i].first]);
        }
    }
    cout << dp[n];
    return 0;
}