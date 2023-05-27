#include<iostream>

using namespace std;

int n, a;
int main () {
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> a; 
		int cnt5 = 0;
		for(int j = 5; j <= a; j *= 5){
			cnt5 += a / j; 
		}
		cout << cnt5 << "\n";
	} 
	return 0;
}