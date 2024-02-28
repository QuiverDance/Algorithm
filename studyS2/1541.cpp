/*
    #1541 잃어버린 괄호
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int n, ret;
vector<int> v;
vector<char> op;
string s;
int main(){
    cin >> s;
    string temp;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9') temp += s[i];
        else{
            op.push_back(s[i]);
            v.push_back(stoi(temp));
            temp = "";
        }
    }
    v.push_back(stoi(temp));
    ret += v[0];
    int sum = 0, flag = 0;
    for(int i = 1; i < v.size(); i++){
        if(op[i - 1] == '-'){
            sum += v[i];
            if(flag){
                ret -= sum, sum = 0;
            }
            flag = 1;
        }
        else {
            if(flag){
                sum += v[i];
            }
            else ret += v[i];
        }
    }
    cout << ret - sum;
    return 0;
}