#include<iostream>
using namespace std;

int t, n, ret;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        ret = 0;
        cin >> n;
        for(int i = 5; i <= n; i *= 5){
            ret += n / i;
        }
        cout << ret << '\n';
    }
    return 0;
}