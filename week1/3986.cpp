#include<iostream>
#include<string>
#include<stack>

using namespace std;

int n, cnt = 0;
string str;

bool checkGoodWord(string s){
    stack<char> st;
    for(auto it : s){
        if(st.size() != 0 && st.top() == it) st.pop();
        else st.push(it);
    }
    if(st.size() == 0) return true;
    return false;    
}
int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        if(checkGoodWord(str)) cnt++;
    }
    cout << cnt;
    return 0;
}