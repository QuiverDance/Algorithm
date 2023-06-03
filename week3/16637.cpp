#include<iostream>
#include<vector> 

using namespace std;

vector<int> numList; 
vector<int> operList; 
int n, ret = -987654321;
string s;  
int oper(char a, int b, int c){
    if(a == '+') return b + c; 
    if(a == '-') return b - c; 
    if(a == '*') return b * c;  
} 

void go(int here, int sum){
    if(here == numList.size() - 1){ 
        ret = max(ret, sum); 
        return;
    }  
    go(here + 1, oper(operList[here], sum, numList[here + 1]));

    if(here + 2 <= numList.size() - 1){
        int temp = oper(operList[here + 1], numList[here + 1], numList[here + 2]); 
        go(here + 2, oper(operList[here], sum, temp));  
    } 
    return;
} 
int main(){
    cin >> n;  
    cin >> s; 
    for(int i = 0; i < n; i++){
        if(i % 2 == 0)numList.push_back(s[i] - '0');
        else operList.push_back(s[i]);
    } 
    go(0, numList[0]);  
    cout << ret << "\n";
    return 0;
} 