/*
    #10819 차이를 최대로
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, ret;
vector<int> v;
int main(){
    cin >> n;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num; v.push_back(num);
    } 
    sort(v.begin(), v.end());
    int sum;
    do{
        sum = 0;
        for(int i = 1; i < v.size(); i++){
            sum += abs(v[i - 1] - v[i]);
        }
        ret = max(ret, sum);
    }while(next_permutation(v.begin(), v.end()));
    cout << ret;
    return 0;
}