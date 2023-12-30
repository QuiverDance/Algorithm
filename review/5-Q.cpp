#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, l, ret;
vector<pair<int, int>> v;
int main(){
    cin >> n >> l;
    int s, e;
    for(int i = 0; i < n; i++){
        cin >> s >> e;
        v.push_back({s, e});
    }
    sort(v.begin(), v.end());

    int cur = 0;
    for(pair<int, int> it : v){
        if(cur < it.first) cur = it.first;
        while(cur < it.second){
            cur += l; ret++;
        }
    }
    cout << ret;
    return 0;
}