#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ret;
vector<pair<int, int>> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    int end = v[0].second;
    ret = v[0].second - v[0].first;
    for(int i = 1; i < v.size(); i++){
        if(end >= v[i].second) continue;
        if(end >= v[i].first) ret += v[i].second - end;
        else ret += v[i].second - v[i].first;
        end = v[i].second;
    }
    cout << ret;
    return 0;
}