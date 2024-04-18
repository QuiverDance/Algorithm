/*
    #15686 치킨 배달
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int n, m, ret = 1e9;
vector<pair<int, int>> h, c;
vector<vector<int>> c_list;
void combi(int idx, vector<int> b){
    if(b.size() == m){
        c_list.push_back(b);
        return;
    }
    for(int i = idx; i < c.size(); i++){
        b.push_back(i);
        combi(i + 1, b);
        b.pop_back();
    }
}

int main(){
    cin >> n >> m;
    int num;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> num;
            if(num == 1) h.push_back({i, j});
            else if(num == 2) c.push_back({i, j});
        }
    }
    vector<int> b;
    combi(0, b);
    
    int sum, mn;
    for(auto chi_list : c_list){
        sum = 0;
        for(auto ho : h){
            mn = 1e9;
            for(auto i : chi_list){
                mn = min(mn, abs(ho.first - c[i].first) + abs(ho.second - c[i].second));
            }
            sum += mn;
        }
        ret = min(ret, sum);
    }
    cout << ret;
    return 0;
}