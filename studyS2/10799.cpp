#include<iostream>
#include<string>
#include<stack>
using namespace std;

string str;
int ret;
char pre;
stack<char> stk;
int main(){
    cin >> str;
    for(char c : str){
        if(c == ')' && pre == '('){
            stk.pop(); ret += stk.size();
        }
        else if(c == ')'){
            stk.pop(); ret += 1;
        }
        else{
            stk.push('(');
        }
        pre = c;
    }
    cout << ret;
    return 0;
}