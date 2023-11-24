#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, x, ret;
vector<int> v;
int main(){
    cin >> n;
    int t;
    for(int i = 0; i < n; i++){ cin >> t; v.push_back(t); }
    cin >> x;
    sort(v.begin(), v.end());
    int s = 0; int e = n - 1;
    while(s < e){
        if(v[s] + v[e] == x) ret++;
        if(v[s] + v[e] < x) s++;
        else e--;
    }
    cout << ret;
    return 0;
}