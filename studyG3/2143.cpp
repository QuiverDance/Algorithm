/*
    #2143 두 배열의 합
*/
#include<iostream>
#include<map>
using namespace std;

int t, n, m, sum1[1004], sum2[1004];
map<int, int> mp;
long long ret;
int main(){
    cin >> t >> n;
    int num;
    for(int i = 1; i <= n; i++){
        cin >> num;
        sum1[i] = sum1[i - 1] + num;
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> num;
        sum2[i] = sum2[i - 1] + num;
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            mp[sum1[j] - sum1[i]]++;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = i + 1; j <= m; j++){
            ret += mp[t - (sum2[j] - sum2[i])];
        }
    }
    cout << ret;
    return 0;
}