#include<iostream>
#include<string>
#include<map>
using namespace std;

int n, m, cnt;
string s;
map<string, int> mp;
int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s; mp[s]++;
    }
    for(int i = 0; i < m; i++){
        cin >> s;
        if(mp[s] > 0) cnt++;
    }
    cout << cnt;
    return 0;
}