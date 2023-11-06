#include<iostream>
#include<string>
using namespace std;

int n, m, a[5][5], ret = 0;
string s;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++) a[i][j] = s[j] - '0';
    }
    for(int k = 0; k < (1 << n * m); k++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            int cur = 0;
            for(int j = 0; j < m; j++){
                int idx = i * m + j;
                if((k & (1 << idx)) == 0){
                    cur = cur * 10 + a[i][j];
                }
                else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        for(int j = 0; j < m; j++){
            int cur = 0;
            for(int i = 0; i < n; i++){
                int idx = i * m + j;
                if((k & (1 << idx))){
                    cur = cur * 10 + a[i][j];
                }
                else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        ret = max(ret, sum);
    }
    cout << ret;
    return 0;
}