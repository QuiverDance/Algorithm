/*
    #10972 다음 순열
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> v, temp;
int main(){
    cin >> n;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
        temp.push_back(num);
    }
    next_permutation(v.begin(), v.end());
    sort(temp.begin(), temp.end());
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(v[i] != temp[i]) flag = 1;
    }
    if(flag){
        for(int i = 0; i < n; i++) cout << v[i] << " ";
    }
    else cout << -1;
    return 0;
}