#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
const int maxn = 100000 + 5;
int dp[maxn][11];
int Hash[maxn][11];
int n;
int main() {
	while(scanf("%d", &n) == 1 && n) {
		memset(Hash, 0, sizeof(Hash));
		int tmax = 0;
		int t, x;
		for(int i = 0; i < n; i++) {
			scanf("%d%d", &x, &t);
			tmax = max(t, tmax);
			Hash[t][x]++;
		}
		memset(dp[0], -1, sizeof(dp[0]));
		dp[0][5] = 0;
		for(int i = 1; i <= tmax; i++) {
			for(int j = 0; j <= 10; j++) {
				dp[i][j] = -1;
				int d = Hash[i][j];
				if(dp[i-1][j] != -1) dp[i][j] = dp[i-1][j] + d;
				if(j > 0 && dp[i-1][j-1] != -1) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + d);
				if(j < 10 && dp[i-1][j+1] != -1) dp[i][j] = max(dp[i][j], dp[i-1][j+1] + d);
			}
		} 
		int ans = 0;
		for(int i = 0; i <= 10; i++) {
			ans = max(ans, dp[tmax][i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
