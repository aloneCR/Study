#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define INF (1<<30) + 5
const int maxn = 2000 + 5;
int dp[maxn][maxn];
int a[maxn];
int main() {
	int n, k;
	while(scanf("%d%d", &n, &k) == 2) {
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+n+1);
		for(int i = 1; i <= k; i++) dp[0][i] = INF;
		dp[0][0] = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j <= k; j++) {
				dp[i][j] = i>=2*j ? dp[i-1][j] : INF;
				if(i >= 2) dp[i][j] = min(dp[i][j], dp[i-2][j-1] + (a[i]-a[i-1])*(a[i]-a[i-1])); 
			}
		}
		printf("%d\n", dp[n][k]);
	}
	return 0;
}
