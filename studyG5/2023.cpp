/*
    #2023 신기한 소수
*/
#include<iostream>
#include<string>
using namespace std;

int n, a[] = {1, 2, 3, 5, 7, 9};
bool isPrime(int num){
    if(num == 1) return false;
    if(num == 2) return true;
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

void solve(string s){
    if(s.length() == n){
        cout << s << '\n'; return;
    }
    for(int i = 0; i < 6; i++){
        s.push_back(a[i] + '0');
        if(isPrime(stoi(s)))
            solve(s);
        s.pop_back();
    }
}
int main(){
    cin >> n;
    solve("");
    return 0;
}