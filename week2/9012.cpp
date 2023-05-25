#include<iostream>
#include<string>
#include<stack>

using namespace std;

int T;
string s;
int main(void){
    cin >> T;
    while(T--){
        cin >> s;
        stack<int> stk;
        for(char c : s){
            if(c == ')' && stk.size() && stk.top() == '(')
                stk.pop();
            else
                stk.push(c);
        }
        if(!stk.size()) 
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}