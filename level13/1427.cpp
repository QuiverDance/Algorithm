#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string s;
vector<char> v;
int main(void){
    cin >> s;
    for(int i = 0; i < s.length(); i++) v.push_back(s[i]);
    sort(v.begin(), v.end());
    for(int i = s.length() - 1; i >= 0; i--){
        cout << v[i];
    }
    return 0;
}