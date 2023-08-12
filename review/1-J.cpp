#include<iostream>
#include<string>
#include<map>
using namespace std;

int t, n, ret;
string s1, s2;
map<string, int> mp;

int main(){
    cin >> t;
    while(t--){
        ret = 1; mp.clear();
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> s1 >> s2; mp[s2]++;
        }
        for(auto it : mp){
            ret *= (it.second + 1);
        }
        cout << ret - 1 <<'\n';
    }
    return 0;
}