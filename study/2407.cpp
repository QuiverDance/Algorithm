/*
    #2407 조합
*/
#include <iostream>
#include<algorithm>
#include <string>
using namespace std;

int n, m;
string dp[104][104];

string sum(string num1, string num2){
    int sum = 0;
    string ret;
    while(num1.size() || num2.size() || sum){
        if(num1.size()){
            sum += num1.back() - '0';
            num1.pop_back();
        }
        if(num2.size()){
            sum += num2.back() - '0';
            num2.pop_back();
        }
        ret.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string combi(int a, int b){
    if(b == 0 || b == a) return "1";
    if(b == 1) return to_string(a);
    string &ret = dp[a][b];
    if(ret != "") return dp[a][b];
    ret = sum(combi(a - 1, b), combi(a - 1, b - 1));
    //printf("%dC%d = %s\n", a, b, ret.c_str());
    return ret;
}

int main() {
    cin >> n >> m;
    cout << combi(n, min(m, n - m));
    return 0;
}