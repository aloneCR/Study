#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 32768 + 5;
long long dp[maxn][4];
int main() {
    int n;
	for(int i = 1; i <= 3; i++) dp[0][i] = 1;
	for(int i = 1; i <= maxn-2; i++) {
		dp[i][1] = dp[i-1][1];
		dp[i][2] = 0;
		for(int j = 1; j <= 2; j++) {
			if(i-j>=0) dp[i][2] += dp[i-j][j];  
		}
		dp[i][3] = 0;
		for(int j = 1; j <= 3; j++) {
			if(i-j>=0) dp[i][3] += dp[i-j][j];
		}
	}
	while(scanf("%d", &n) == 1) {
		printf("%lld\n", dp[n][3]);
	}
    return 0;
}
