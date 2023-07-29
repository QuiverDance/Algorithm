#include<iostream>
#include<map>
using namespace std;

int n, m, t;
map<int, int> mp;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t; mp[t]++;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> t;
        if(mp[t] > 0) cout << mp[t] << " ";
        else cout << 0 << " ";
    }
    return 0;
}