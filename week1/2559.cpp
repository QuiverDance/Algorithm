#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, K;
int sum[100001];
vector<int> result;
int main(void){
    cin >> N >> K;
    int a;
    for(int i = 1; i <= N; i++){
        cin >> a;
        sum[i] = sum[i-1] + a;
    }

    for(int i = K; i <= N; i++)
        result.push_back(sum[i] - sum[i-K]);

    cout << *max_element(result.begin(), result.end());
}