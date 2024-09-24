#include<iostream>
#include<string>
#include<set>
using namespace std;

int n, m, cnt;
string s1, s2;
set<string, greater<string>> st;
int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s1 >> s2;
        if(s2 == "enter") st.insert(s1);
        else st.erase(s1);
    }
    for(auto it : st)
        cout << it << '\n';
    return 0;
}