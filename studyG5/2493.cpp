/*
    #2493 탑
*/
#include<iostream>
#include<stack>
using namespace std;

int n, a[500004], ret[500004];
stack<int> stk;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = n; i >= 1; i--){
        while(!stk.empty() && a[stk.top()] <= a[i]){
            ret[stk.top()] = i; stk.pop();
        }
        stk.push(i);
    }
    for(int i = 1; i <= n; i++) cout << ret[i] << " ";
    return 0;
}