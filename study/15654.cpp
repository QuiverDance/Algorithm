/*
    #15652 N과 M (5)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a[10], visited[10004];
vector<int> v;

void solve(int idx){
    if(idx == m){
        for(int i = 0; i < m; i++) cout << a[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++){
        if(visited[v[i]]) continue;
        visited[v[i]] = 1;
        a[idx] = v[i];
        solve(idx + 1);
        visited[v[i]] = 0;
    }
}

int main() {
    cin >> n >> m;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    solve(0);
    return 0;
}