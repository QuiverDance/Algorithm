#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n = 5, t, sum = 0;
vector<int> v;
int main(void){
    for(int i = 0; i < n; i++){ cin >> t; v.push_back(t); sum += t; }
    sort(v.begin(), v.end());
    cout << sum / 5 << '\n' << v[2];
    return 0;
}