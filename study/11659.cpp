/*
    #11659 구간 합 구하기 4
*/
#include<iostream>
using namespace std;

int n, m, sum[100004];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sum[0] = 0;
    cin >> n >> m;
    int num;
    for(int i = 1; i <= n; i++){
        cin >> num;
        sum[i] = sum[i - 1] + num;
    }
    int st, ed;
    for(int i = 0; i < m; i++){
        cin >> st >> ed;
        cout << sum[ed] - sum[st - 1] << '\n';
    }
    return 0;
}