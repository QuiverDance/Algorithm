/*
    #1935 후위 표기식2
*/
#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

int n;
string str;
stack<double> stk;
map<char, int> mp;

double cal(double a, double b, char oper){
    if(oper == '+') return (double)a + b;
    if(oper == '-') return (double)a - b;
    if(oper == '*') return (double)a * b;
    return (double)a / b;   
}

int main() {
    cin >> n;
    cin >> str;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        mp['A' + i] = num;
    }
    double num1, num2;
    for(char c : str){
        if(c >= 'A' && c <= 'Z') stk.push(mp[c]);
        else{
            num1 = stk.top(); stk.pop();
            num2 = stk.top(); stk.pop();
            stk.push(cal(num2, num1, c));
        }
    }
    printf("%0.2lf", stk.top());
    return 0;
}