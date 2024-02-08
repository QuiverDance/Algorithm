/*
    #1735 분수 합
*/
#include <iostream>
using namespace std;

int n1, n2, n3, n4, num1, num2;
int getGcd(int a, int b){
    return b == 0 ? a : getGcd(b, a % b);
}

int main() {
    cin >> n1 >> n2 >> n3 >> n4;
    num1 = n1 * n4 + n2 * n3;
    num2 = n2 * n4;
    int d = getGcd(max(num1, num2), min(num1, num2));
    cout << num1 / d << " " << num2 / d;
    return 0;
}