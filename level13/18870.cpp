#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int n, t, cnt = 1;
vector<int> v, temp;
map<int, int> mp;

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t;
        v.push_back(t);
    }
    temp = v;
    sort(temp.begin(), temp.end());
    for(int i = 0; i < n; i++){
        if(mp[temp[i]] > 0) continue;
        mp[temp[i]] = cnt++;
    }
    for(int i = 0; i < n; i++) cout << mp[v[i]] - 1 << " ";
    return 0;
}