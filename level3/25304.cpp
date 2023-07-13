#include<iostream>
using namespace std;

int x, n, a, b, sum;
int main(void){
    cin >> x >> n;
    while(n--){
        cin >> a >> b;
        sum += a * b;
    }
    if(x == sum) cout << "Yes";
    else cout << "No";
    return 0;
}