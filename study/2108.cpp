/*
    #2108 통계학
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int n, sum;
vector<int> v;
vector<pair<int, int>> v2;
map<int, int> mp;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main() {
    cin >> n;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
        mp[num + 500000]++;
        sum += num;
    }
    sort(v.begin(), v.end());
    cout << (int)round((double)sum / n) << '\n';
    cout << v[n / 2] << '\n';
    for(auto it : mp){
        v2.push_back({it.second, it.first});    
    }
    sort(v2.begin(), v2.end(), cmp);
    if(v2.size() > 1 && v2[0].first == v2[1].first) cout << v2[1].second - 500000 << '\n';
    else cout << v2[0].second - 500000 << '\n';
    cout << v[n -1] - v[0];
    return 0;
}