/*
    #15663 N과 M(9)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v;

void solve(vector<int> b, int visited){
    if(b.size() == m){
        for(int i = 0; i < m; i++) cout << b[i] << " ";
        cout << '\n';
        return;
    }
    int last = 0;
    for(int i = 0; i < v.size(); i++){
        if(visited & (1 << i) || last == v[i]) continue;
        last = v[i];
        b.push_back(v[i]);
        solve(b, visited | (1 << i));
        b.pop_back();
    }
}

int main(){
    cin >> n >> m;

    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    vector<int> b;
    solve(b, 0);
    return 0;
}