#include<iostream>
#include<stack>
#include<string>
using namespace std;

int n, ret, a[200004];
stack<int> stk;
string s;
int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') stk.push(i);
        else if(s[i] == ')' && !stk.empty()){
            a[i] = 1; a[stk.top()] = 1;
            stk.pop();
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            ret = max(ret, cnt);
            cnt = 0;
        }
        else cnt++;
    }
    ret = max(ret, cnt);
    cout << ret;
    return 0;
}