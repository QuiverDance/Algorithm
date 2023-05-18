#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void){
    string str;
    cin >> str;

    string temp = str;
    reverse(temp.begin(), temp.end());
    if(temp == str) cout << 1;
    else cout << 0;

    return 0;
}