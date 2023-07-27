#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n;
string s;
vector<string> v;
set<string> se;

bool cmp(string s1, string s2){
    if(s1.length() == s2.length()) return s1 < s2;
    if(s1.length() < s2.length()) return true;
    else return false;
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        se.insert(s);
    }
    for(string it : se) v.push_back(it);
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
    return 0;
}