#include<iostream>
#include<string>
#include<set>
using namespace std;

string s;
set<string> st;
int main(void){
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        for(int k = 1; k <= s.length() - i; k++) st.insert(s.substr(i, k));
    }
    cout << st.size();
    return 0;
}