#include<iostream>

using namespace std;

long long A, B, C;
long long solve(long a, long b){
    if(b == 1) return a % C;

    long long ret = solve(a, b / 2);
    ret = (ret * ret) % C;
    if(b % 2) ret = (ret * a) % C;
    return ret;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> A >> B >> C;
    cout << solve(A, B);
    return 0;
}