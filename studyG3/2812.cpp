/*
    #2812 크게 만들기
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int n, k, cnt;
string str;
stack<int> stk, ret;
int main(){
    cin >> n >> k;
    cin >> str;
    for(char c : str){
        while(!stk.empty() && stk.top() < c - '0' && cnt < k){
            cnt++;
            stk.pop();
        }
        stk.push(c - '0');
    }
    while(cnt < k){
        cnt++;
        stk.pop();
    }
    while(!stk.empty()){
        ret.push(stk.top());
        stk.pop();
    }
    while(!ret.empty()){
        cout << ret.top();
        ret.pop();
    }
    return 0;
}