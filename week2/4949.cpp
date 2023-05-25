#include<iostream>
#include<string>
#include<stack>

using namespace std;

string s;
int main(void){
    while(true){
        getline(cin, s);
        if(s == ".") break;;
        stack<int> stk;
        for(char c : s){
            if(c != '(' && c != ')' && c != '[' && c != ']') continue;
            if(c == ')' && stk.size() && stk.top() == '(')
                stk.pop();
            else if(c == ']' && stk.size() && stk.top() == '[')
                stk.pop();
            else
                stk.push(c);
        }
        if(!stk.size()) 
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
    return 0;
}