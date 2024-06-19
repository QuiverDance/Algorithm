/*
    #9935 문자열 폭발
*/
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

string str, mark, ret;
stack<char> stk;
int main(){
    cin >> str >> mark;
    reverse(mark.begin(), mark.end());
    for(char c : str){
        stk.push(c);
        stack<char> temp;
        for(char t : mark){
            if(!stk.empty() && t == stk.top()){
                temp.push(stk.top()); stk.pop();
                continue;
            }
            while(!temp.empty()){
                stk.push(temp.top()); temp.pop();
            }
            break;
        }
    }
    while(!stk.empty()){
        ret += stk.top(); stk.pop();
    }
    reverse(ret.begin(), ret.end());
    cout << (ret == "" ? "FRULA" : ret);
    return 0;
}