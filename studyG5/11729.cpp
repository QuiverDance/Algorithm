/*
    #11729 하노이 탑 이동 순서
*/
#include<iostream>
#include<vector>
using namespace std;

int n, ret;
vector<pair<int, int>> v;
void solve(int k, int st, int ed, int mid){
    ret++;
    if(k == 1){
        v.push_back({st, ed}); return;
    }
    solve(k - 1, st, mid, ed);
    v.push_back({st, ed});
    solve(k - 1, mid, ed, st);
}

int main(){
    cin >> n;
    solve(n, 1, 3, 2);
    cout << ret << '\n';
    for(auto it : v)
        cout << it.first << " " << it.second << '\n';
    return 0;
}