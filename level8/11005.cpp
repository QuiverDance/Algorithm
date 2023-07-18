#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, b;
vector<int> v;
int main(void){
    cin >> n >> b;
    while(n > 1){
        v.push_back(n % b);
        n /= b;
    }
    if(n == 1) v.push_back(1);
    reverse(v.begin(), v.end());
    for(int it : v){
        if(it >= 10) cout << char(it - 10 + 'A');
        else cout << it;
    }
    return 0;
}