/*
    #1449 수리공 항승
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, l, ret;
vector<int> v;
int main(){
    cin >> n >> l;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int pos = 0;
    for(int hole : v){
        if(pos >= hole) continue;
        if(pos < hole){
            ret++; pos = hole - 1 + l;
        }
    }
    cout << ret;
    return 0;
}