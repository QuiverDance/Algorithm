/*
    #2004 조합 0의 개수
*/
#include<iostream>
#define ll long long
using namespace std;


int n, m;
int solve(int x, int d){
    int cnt = 0;
    for(ll i = d; x / i >= 1; i *= d){
        cnt += x / i;
    }
    return cnt;
}
int main(){
    cin >> n >> m;
    
    int cnt2 = solve(n, 2) - solve(n - m, 2) - solve(m, 2);
    int cnt5 = solve(n, 5) - solve(n - m, 5) - solve(m, 5);
        
    cout << min(cnt2, cnt5);
    return 0;
}