#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

string s1, s2, ret;
stack<int> stk1, stk2;
int main(void){
    cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i++) stk1.push(s1[i] - '0');
    for(int i = 0; i < s2.size(); i++) stk2.push(s2[i] - '0');

    int a, b, carry = 0, num;
    while(stk1.size() && stk2.size()){
        a = stk1.top(); b = stk2.top();
        stk1.pop(); stk2.pop();
        if(a + b + carry >= 10){
            num = a + b + carry - 10;
            carry = 1;
        }
        else{
            num = a + b + carry;
            carry = 0;
        }
        ret += num + '0';
    }
    while(stk1.size()){
        if(stk1.top() + carry >= 10){
            num = stk1.top() + carry - 10;
            carry = 1;
        }
        else{
            num = stk1.top() + carry;
            carry = 0;
        }
        stk1.pop();
        ret += num + '0';
    }
    while(stk2.size()){
        if(stk2.top() + carry >= 10){
            num = stk2.top() + carry - 10;
            carry = 1;
        }
        else{
            num = stk2.top() + carry;
            carry = 0;
        }
        stk2.pop();
        ret += num + '0';
    }
    if(carry == 1) ret += '1';

    reverse(ret.begin(), ret.end());
    cout << ret;
}