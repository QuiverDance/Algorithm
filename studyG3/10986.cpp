/*
    #10986 나머지 합
*/
#include<iostream>
using namespace std;

long long n, m, sum, cnt[1004], ret;
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    int num;
    for(int i = 1; i <= n; i++){
        cin >> num;
        sum += num;
        sum %= m;
        cnt[sum]++;
    }
    ret = cnt[0];
    for(int i = 0; i < m; i++){
        ret += cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ret;
    return 0;
}