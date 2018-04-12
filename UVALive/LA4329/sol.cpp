#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 5;
int bit[maxn], a[20000+5], low[20000+5];
int max_rank;

int lowbit(int x) {
	return x&-x;
}

int sum(int x) {
	int ret = 0;
	while(x > 0) {
		ret += bit[x];
		x -= lowbit(x);
	}
	return ret;
}

void add(int x, int d) {
	while(x <= max_rank) {
		bit[x] += d;
		x += lowbit(x);
	}
}

int main() {
	int T, n;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		memset(bit, 0, sizeof(bit));
		max_rank = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			max_rank = max(max_rank, a[i]);
		}
		for(int i = 0; i < n; i++) {
			low[i] = sum(a[i]-1);
			add(a[i], 1);
		}
		memset(bit, 0, sizeof(bit));
		long long ans = 0;
		for(int i = n-1; i >= 0; i--) {
			int x = sum(a[i]-1);
			ans += 1LL*low[i]*(n-i-1-x) + 1LL*(i-low[i])*x;
			add(a[i], 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
