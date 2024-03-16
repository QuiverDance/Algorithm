/*
    #1931 회의실 배정
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ret;
vector<pair<int, int>> v;
int main(){
    cin >> n;
    int st, ed;
    for(int i = 0; i < n; i++){
        cin >> st >> ed;
        v.push_back({ed, st});
    }
    sort(v.begin(), v.end());
    int cur = 0;
    for(auto it : v){
        if(cur <= it.second){
            ret++; cur = it.first;
        }
    }
    cout << ret;
    return 0;
}