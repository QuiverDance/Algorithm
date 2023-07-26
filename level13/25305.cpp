#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k, t;
vector<int> v;
int main(void){
    cin >> n >> k;
    for(int i = 0; i < n; i++){ cin >> t; v.push_back(t);}
    sort(v.begin(), v.end());
    cout << v[n - k];
    return 0;
}