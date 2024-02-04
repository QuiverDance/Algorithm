/*
    N과 M(6)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v;

void combi(int idx, vector<int> b){
    if(b.size() == m){
        for(int i = 0; i < m; i++) cout << b[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = idx; i < n; i++){
        b.push_back(v[i]);
        combi(i + 1, b);
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
    combi(0, b);
    return 0;
}