/*
    #1744 수 묶기
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ret;
vector<int> v1, v2;
int main() {
    cin >> n;
    int num;
    for(int i = 0; i < n; i++) {
        cin >> num;
        if(num > 0) v1.push_back(num);
        else v2.push_back(num);
    }
    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end());
    
    if(v1.size() % 2) { ret += v1[v1.size() - 1]; v1.pop_back();}
    for(int i = 0; i < v1.size(); i += 2) {ret += max(v1[i] * v1[i + 1], v1[i] + v1[i + 1]); }
    
    if(v2.size() % 2) { ret += v2[v2.size() - 1]; v2.pop_back();}
    for(int i = 0; i < v2.size(); i += 2) ret += v2[i] * v2[i + 1];
    cout << ret;
    return 0;
}