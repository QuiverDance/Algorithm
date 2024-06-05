/*
    #1806 부분합
*/
#include<iostream>
using namespace std;

int n, s, sum[100004], ret = 1e9;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    int num;
    for(int i = 1; i <= n; i++){
        cin >> num;
        sum[i] = num + sum[i - 1];
    }

    int l = 0, r = 1;
    while(r <= n){
        if(sum[r] - sum[l] >= s){
            ret = min(ret, r - l);
        }
        if(sum[r] - sum[l] > s) l++;
        else r++;
    }
    cout << (ret == 1e9 ? 0 : ret);
    return 0;
}