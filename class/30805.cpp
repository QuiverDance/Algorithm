/*
    #30805 사전 순 최대 공통 부분 수열
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> a, b, ret;
int main(){
    cin >> n;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        a.push_back(num);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> num;
        b.push_back(num);
    }
    while(!a.empty() && !b.empty()){
        int a_max = max_element(a.begin(), a.end()) - a.begin();
        int b_max = max_element(b.begin(), b.end()) - b.begin();
        if(a[a_max] == b[b_max]){
            ret.push_back(a[a_max]);
            a.erase(a.begin(), a.begin() + a_max + 1);
            b.erase(b.begin(), b.begin() + b_max + 1);
        }
        else if(a[a_max] > b[b_max])
            a.erase(a_max + a.begin());
        else
            b.erase(b_max + b.begin());
    }
    cout << ret.size() << '\n';
    for(int it : ret) cout << it << " ";
    return 0;
}