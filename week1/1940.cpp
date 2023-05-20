#include<iostream>
#include<vector>

using namespace std;

int n, m;
int num[15000];
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cin >> m;

    if(m > 200000){
        cout << 0;
        return 0;
    }
    
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        num[i] = a;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(num[i] + num[j] == m)
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}