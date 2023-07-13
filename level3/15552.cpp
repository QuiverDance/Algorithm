#include<iostream>
using namespace std;

int t, a, b;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << a + b << '\n';
    }
    return 0;
}