#include<iostream>
using namespace std;
typedef long long ll;

ll n, sum[500004], ret;
int main(void){
    cin >> n;
    sum[0] = 0;
    for(int i = 1; i < n - 1; i++){
        sum[i] = sum[i - 1] + i;
        ret += sum[i];
    }
    cout << ret << '\n' << 3;
    return 0;
}