#include<iostream>
#include<string>
using namespace std;

int x;
string ret = "";
int main(){
    cin >> x;
    while(x > 0){
        if(x % 2 == 0) ret = "0" + ret;
        else ret = "1" + ret;
        x /= 2;
    }
    int cnt = 0;
    for(int i = 0; i < ret.size(); i++){
        if(ret[i] == '1') cnt++;
    }
    cout << cnt;
    return 0;
}