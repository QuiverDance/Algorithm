/*
    #2011 암호코드
*/
#include<iostream>
#include<string>
#define DIV 1000000
using namespace std;

string str;
int dp[5004];
int main()
{
	cin >> str;
    if(str[0] - '0' == 0){
        cout << 0; return 0;
    }
	str = " " + str;
	dp[0] = 1; dp[1] = 1;
	for (int i = 2; i < str.length(); i++) {
		if (str[i] > '0' && str[i] <= '9')
			dp[i] = dp[i - 1];
		if (str[i - 1] == '1' || str[i - 1] == '2' && str[i] >= '0' && str[i] <= '6')
			dp[i] += dp[i - 2];
		dp[i] %= DIV;
	}

	cout << dp[str.length() - 1] % DIV;
	return 0;
}