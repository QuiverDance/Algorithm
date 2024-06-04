/*
    #17298 오큰수
*/
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int n, a[1000004], ret[1000004];
stack<int> stk;
int main(){
    memset(ret, -1, sizeof(ret));
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    for(int i = 0; i < n; i++){
        while(!stk.empty() && a[stk.top()] < a[i]){
            ret[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }
    
    for(int i = 0; i < n; i++) cout << ret[i] << " ";
    return 0;
}