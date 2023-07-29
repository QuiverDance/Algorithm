#include<iostream>
#include<string>
#include<map>
using namespace std;

int n, m;
string s;
map<string, int> mp1;
map<int, string> mp2;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        mp1[s] = i + 1;
        mp2[i + 1] = s;
    }
    for(int i = 0; i < m; i++){
        cin >> s;
        if(atoi(s.c_str()) > 0) cout << mp2[atoi(s.c_str())] << '\n';
        else cout << mp1[s] << '\n'; 
    }
    return 0;
}