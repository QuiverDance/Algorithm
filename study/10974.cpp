/*
    #10974 모든 순열
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> v;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        v.push_back(i);
    }
    do{
        for(int it : v) cout << it << " ";
        cout << '\n';
    }while(next_permutation(v.begin(), v.end()));
    return 0;
}