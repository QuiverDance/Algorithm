/*
    #1946 신입 사원
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, n, ret, flag, mn;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    int num1, num2;
    while(t--){
        cin >> n;
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++){
            cin >> num1 >> num2;
            v.push_back({num1, num2});
        }
        sort(v.begin(), v.end());

        ret = 0, mn = 1e9;
        for(int i = 0; i < n; i++){
            flag = 1;
            if(v[i].second > mn) continue;
            mn = min(mn, v[i].second);
            ret++;
        }
        cout << ret << '\n';
    }
}