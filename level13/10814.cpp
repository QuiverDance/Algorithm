#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n, t;
string s;
vector<pair<int, string>> v;

bool cmp(pair<int, string> a, pair<int, string> b){
    if(a.first == b.first) return false;
    if(a.first < b.first) return true;
    else return false;
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t >> s;
        v.push_back({t, s});
    }
    stable_sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++)
        cout << v[i].first << " " << v[i].second << '\n';
    return 0;
}