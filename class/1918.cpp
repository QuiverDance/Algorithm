/*
    #1918 후위 표기식
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

string str, ret = "";
stack<char> stk;
bool isOperater(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/') return true;
    return false;
}
bool getPriority(char a, char b){
    if(a == '(') return false;
    if(b == '+' || b == '-'){
        return true;   
    }
    else{
        if(a != '+' && a != '-') return true;
        return false;
    }
}
int main() {
    cin >> str;
    for(char c : str){
        if(c == '('){
            stk.push(c); continue;
        }
        if(c == ')'){
            while(!stk.empty()){
                if(stk.top() == '('){
                    stk.pop();
                    break;
                }
                ret += stk.top();
                stk.pop();
            }
            continue;
        }
        if(isOperater(c)){
            while(!stk.empty() && getPriority(stk.top(), c)){
                ret += stk.top();
                stk.pop();
            }
            stk.push(c);
            continue;
        }
        ret += c;
    }
    while(!stk.empty()){
        ret += stk.top();
        stk.pop();
    }
    cout << ret;
    return 0;
}