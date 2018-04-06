#include <stdio.h>
#include <string.h>
typedef long long LL;
const int maxn = 10000000 + 5;
bool vis[maxn];

int main() {
	int l, r, n;
	while(scanf("%d", &n) == 1) {
		scanf("%d%d", &l, &r);
		int tol = 0;
		for(int x = 0; x <= maxn*10; x++) {
			LL val = (1LL*n*x)^x;
			if(val >= l && val <= r) {
				tol += !vis[val];
				vis[val] = 1;
			}
		}
		printf("%d\n", tol);
	}
	return 0;
}
