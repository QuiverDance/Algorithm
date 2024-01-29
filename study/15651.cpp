/*
    #15652 N과 M (3)
*/
#include<iostream>
#include<vector>
using namespace std;

int n, m, a[10];
void solve(int idx){
    if(idx == m){
        for(int i = 0; i < m; i++) cout << a[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        a[idx] = i;
        solve(idx + 1);
    }
}
int main(){
    cin >> n >> m;
    vector<int> a;
    solve(0);
    return 0;
}