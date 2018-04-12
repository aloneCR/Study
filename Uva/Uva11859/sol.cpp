#include <stdio.h>
#include <math.h>
const int maxn = 50;
int cnt[10000 + 5];
int val[maxn];

void init() {
	cnt[1] = 0;
	for(int i = 2; i <= 10000; i++) {
		cnt[i] = 0;
		int t = i;
		for(int j = 2; j <= sqrt(t); j++) {
			while(t % j == 0) {
				cnt[i]++;
				t /= j;
			}
		}
		if(t != 1) cnt[i]++;
	}
}

int main() {
	init();
	int n, m, T;
	scanf("%d", &T);
	int kase = 1;
	while(T--) {
		scanf("%d%d", &n, &m); 
		int ans = 0, x;
		for(int i = 0; i < n; i++) {
			val[i] = 0;
			for(int j = 0; j < m; j++) {
				scanf("%d", &x);
				val[i] += cnt[x];
			}
			ans ^= val[i];
		}
		if(ans) printf("Case #%d: YES\n", kase++);
		else printf("Case #%d: NO\n", kase++);
	}
	return 0;
}
