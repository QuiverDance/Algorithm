#include<iostream>
#include<string>
#include<stack>
using namespace std;

int n, ret;
string s;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        stack<char> st;
        cin >> s;
        for(char c : s){
            if(st.empty()){ st.push(c); continue; }
            if(c == st.top()) st.pop();
            else st.push(c);
        }
        if(st.empty()) ret++;
    }
    cout << ret;
    return 0;
}