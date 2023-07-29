#include<iostream>
#include<map>
using namespace std;

int n, m, t, cnt;
map<int, int> mp;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n + m; i++){
        cin >> t; mp[t]++;
    }
    for(auto it : mp){
        if(it.second == 1) cnt++;
    }
    cout << cnt;
    return 0;
}