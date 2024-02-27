/*
    #18870 좌표 압축
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int n;
vector<int> v, v2;
map<int, int> mp;
int main(){
    cin >> n;
    int num;    
    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num); v2.push_back(num);
    }
    sort(v.begin(), v.end());
    int cnt = 1;
    for(int it : v){
        if(mp[it + 1e9] == 0) mp[it + 1e9] = cnt++;
    }
    for(int it : v2) cout << mp[it + 1e9] - 1 << " ";
    return 0;
}