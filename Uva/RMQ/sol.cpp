#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 5;
int d[maxn][15], a[maxn], n;

void RMQ_init(int n) {
	for(int i = 0; i < n; i++) d[i][0] = a[i];
	for(int j = 1; (1<<j) <= n; j++) {
		for(int i = 0; i + (1<<j) - 1 < n; i++) {
			d[i][j] = min(d[i][j-1], d[i+(1<<(j-1))][j-1]);
		}
	}
}

int RMQ(int l, int r) {
	int k = 0;
	while((1<<(k+1)) <= r-l+1) {
		k++;
	}
	return min(d[l][k], d[r-(1<<k)+1][k]);
}

int main() {
	int q, l, r;
	while(scanf("%d", &n) == 1) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		RMQ_init(n);
		scanf("%d", &q);
		for(int i = 0; i < q; i++) {
			scanf("%d%d", &l, &r);
			printf("%d\n", RMQ(l ,r));
		}
	}
	return 0;
} 
