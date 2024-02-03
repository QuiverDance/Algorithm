/*
    N과 M(8)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v;

void solve(int idx, vector<int> b){
    if(idx == m){
        for(int i = 0; i < m; i++) cout << b[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++){
        if(idx > 0 && b[idx - 1] > v[i]) continue;
        b.push_back(v[i]);
        solve(idx + 1, b);
        b.pop_back();
    }
}

int main(){
    cin >> n >> m;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num; v.push_back(num);
    }
    sort(v.begin(), v.end());
    vector<int> b;
    solve(0, b);
    return 0;
}