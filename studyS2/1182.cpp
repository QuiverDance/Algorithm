/*
    #1182 부분수열의 합
*/
#include<iostream>
#include<vector>
using namespace std;

int n, s, a[24], ret;
void solve(int idx, int visited, int sum){
    if(idx == n){
        if(sum == s && visited != 0) ret++;
        return;
    }
    solve(idx + 1, visited | (1 << idx), sum + a[idx]);
    solve(idx + 1, visited, sum);
}

int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> a[i];
    solve(0, 0, 0);
    cout << ret;
    return 0;
}