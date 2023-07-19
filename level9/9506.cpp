#include<iostream>
#include<cstring>
using namespace std;

int n, k, cnt, sum, a[100004];
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        cnt = 0; memset(a, 0, sizeof(a)); sum = 0;
        cin >> n;
        if(n == -1) break;
        for(int i = 1; i < n; i++)
            if(n % i == 0){cnt++; a[cnt] = i; sum += i;}
        if(sum == n){
            cout << n << " = ";
            for(int i = 1; i < cnt; i++) cout << a[i] << " + ";
            cout << a[cnt] << '\n';
        }
        else
            cout << n << " is NOT perfect.\n";
    }
    return 0;
}