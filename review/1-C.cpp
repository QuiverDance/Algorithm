#include<iostream>
using namespace std;

int t[104], a, b, c, st, ed, ret;
int main(void){
    cin >> a >> b >> c;
    for(int i = 0; i < 3; i++){
        cin >> st >> ed;
        for(int j = st; j < ed; j++)
            t[j]++;
    }
    for(int i = 1; i <= 100; i++){
        if(t[i] == 1) ret += a;
        else if(t[i] == 2) ret += 2 * b;
        else if(t[i] == 3) ret += 3 * c;
    }
    cout << ret;
    return 0;
}