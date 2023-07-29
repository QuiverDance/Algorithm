#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int n, m;
string s;
map<string, int> mp;
vector<string> v;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n + m; i++){
        cin >> s; mp[s]++;
    }
    for(auto it : mp){
        if(it.second >= 2) v.push_back(it.first);
    }
    cout << v.size() << '\n';
    for(int i = 0; i < v.size(); i++) cout << v[i] << '\n';
    return 0;
}