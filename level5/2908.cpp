#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s1, s2;
int main(void){
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int t1 = atoi(s1.c_str());
    int t2 = atoi(s2.c_str());
    cout << max(t1, t2);
    return 0;
}