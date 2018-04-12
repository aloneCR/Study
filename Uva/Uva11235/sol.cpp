#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 5;
int a[maxn], num[maxn], cnt[maxn];
int l[maxn], r[maxn];
int d[maxn][18];

/*
8 1
47 72 89 96 97 97 98 99
1 8
*/

void RMQ_init(int n) {
	for(int i = 0; i < n; i++) d[i][0] = cnt[i];
	for(int j = 1; (1<<j) <= n; j++) {
		for(int i = 0; i+(1<<j)-1 < n; i++) {
			d[i][j] = max(d[i][j-1], d[i+(1<<(j-1))][j-1]);
		}
	}
}

int RMQ(int l, int r) {
	if(l > r) return 0;
	int k = 0;
	while((1<<(k+1)) <= r-l+1) {
		k++;
	}
	return max(d[l][k], d[r-(1<<k)+1][k]);
}

int main() {
	int n, q;
	while(scanf("%d", &n) == 1 && n) {
		scanf("%d", &q);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		int tol = 0;
		for(int i = 0; i < n;) {
			int x = i;
			while(x < n && a[x] == a[i]) {
				x++;
			}
			for(int j = i; j < x; j++) {
				l[j] = i;
				r[j] = x-1;
				num[j] = tol;
			}
			cnt[tol++] = x-i;
			i = x;
		}
		RMQ_init(tol);
		int ql, qr;
		for(int i = 0; i < q; i++) {
			scanf("%d%d", &ql, &qr);
			ql--;
			qr--;
			if(num[ql] == num[qr]) { //special condition
				printf("%d\n", qr-ql+1);
			} else {
				int ans = r[ql] - ql + 1;
				ans = max(qr - l[qr] + 1, ans);
				ans = max(ans, RMQ(num[ql]+1, num[qr]-1));
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
