/*
    #2467 용액
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ret1, ret2, mn = 2e9;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int lo = 0, hi = n - 1;
    while(lo < hi){
        if(mn > abs(v[lo] + v[hi])){
            mn = abs(v[lo] + v[hi]);
            ret1 = v[lo]; ret2 = v[hi];
        }
        if(v[lo] + v[hi] < 0) lo++;
        else hi--;
    }
    cout << ret1 << " " << ret2;
    return 0;
}