/*
    #1912 연속합
*/
#include<iostream>
using namespace std;

int n, ret = -1e9;
int main(){
    cin >> n;
    int num, sum = 0;
    for(int i = 0; i < n; i++){
        cin >> num;
        ret = max(ret, num);
        sum += num;
        if(sum > 0) ret = max(ret, sum);
        else sum = 0;
    }
    cout << ret;
    return 0;
}