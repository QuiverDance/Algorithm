/*
    #17299 오등큰수
*/
#include<iostream>
#include<map>
#include<stack>
using namespace std;

int n, a[1000004], ret[1000004], cnt[1000004];
stack<int> stk;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = 0; i < n; i++){
        while(!stk.empty() && cnt[a[stk.top()]] < cnt[a[i]]){
            ret[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);        
    }
    while(!stk.empty()){
        ret[stk.top()] = -1;
        stk.pop();
    }
    for(int i = 0; i < n; i++)
        cout << ret[i] << " ";
    return 0;
}