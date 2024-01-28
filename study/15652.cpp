/*
    #15652 N과 M (4)
*/
#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<int> v;
void solve(int idx){
    if(v.size() == m){
        for(int i = 0; i < m; i++) cout << v[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if(v.size() && v[idx - 1] > i) continue;
        v.push_back(i);
        solve(idx + 1);
        v.pop_back();
    }
}
int main(){
    cin >> n >> m;
    vector<int> a;
    solve(0);
    return 0;
}