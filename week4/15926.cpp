#include<iostream>
#include<string>
#include<stack>

using namespace std;

string s;
stack<int> stk;
int n, ret = 0, cnt = 0;
int arr[200004];
int main(void){
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            stk.push(i);
        }
        else if(stk.size()){
            arr[i] = 1;
            arr[stk.top()] = 1;
            stk.pop();
        }
    }
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            ret = max(ret, cnt);
            cnt = 0;
        }
        else cnt++;
    }
    ret = max(ret, cnt);
    cout << ret;
    return 0;
}