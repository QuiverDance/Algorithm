/*
    #2096 내려가기
*/
#include <iostream>
using namespace std;

int n, mn[3], mx[3], temp[3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int num1, num2, num3;
    for(int i = 0 ; i < n; i++){
        cin >> num1 >> num2 >> num3;
        temp[0] = mn[0]; temp[1] = mn[1]; temp[2] = mn[2];
        mn[0] = min(temp[0], temp[1]) + num1;
        mn[1] = min(temp[0], min(temp[1], temp[2])) + num2;
        mn[2] = min(temp[1], temp[2]) + num3;

        temp[0] = mx[0]; temp[1] = mx[1]; temp[2] = mx[2];
        mx[0] = max(temp[0], temp[1]) + num1;
        mx[1] = max(temp[0], max(temp[1], temp[2])) + num2;
        mx[2] = max(temp[1], temp[2]) + num3;
    }
    cout << max(mx[0], max(mx[1], mx[2])) << " " << min(mn[0], min(mn[1], mn[2]));
    return 0;
}