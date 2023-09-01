#include<iostream>
#include<stack>
using namespace std;

int n, a[1000004], num;
stack<pair<int, int>> stk;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        while(stk.size() && num > stk.top().second){
            a[stk.top().first] = num;
            stk.pop();
        }
        stk.push({i, num});    
    }
    while(stk.size()){
        a[stk.top().first] = -1;
        stk.pop();
    }
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}