#include<iostream>
#include<stack>

using namespace std;

int x, ret;
stack<int> stk;

int main(void){
    cin >> x;
    stk.push(64);
    int t, sum = 64;
    while(sum > x){
        t = stk.top();
        stk.pop();
        sum -= t;
        if(sum + t / 2 >= x){
            sum += t / 2;
            stk.push(t / 2);
        }
        else{
            sum += t;
            stk.push(t / 2);
            stk.push(t / 2);
        }
    }
    cout << stk.size();
    return 0;
}