#include <stdio.h>
#include <string.h>

const int maxn = 10000 + 5;
int dp[maxn], a[100+5];

int gcd(int a, int b) {
	return b==0?a:gcd(b,a%b);
}

int main() {
	int n;
	while(scanf("%d", &n) == 1) {
		int g = 0;
		//printf("%d", gcd(0, n));
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			g = gcd(g, a[i]);
		}
		if(g!=1) {
			printf("INF\n");
			continue;
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(int i = 0; i < n; i++) {
			for(int j = a[i]; j < maxn; j++) {
				if(dp[j-a[i]]) dp[j] = 1;
			}
		}
		int ans = 0;
		for(int i = 0; i < maxn; i++) {
			ans += !dp[i];
		} 
		printf("%d\n", ans);
	}
	return 0;
}
