#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 5;
double f[maxn]; //滚动数组
int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) == 2 && n+m) {
		for(int i = 0; i <= n; i++) f[i] = 0;
		int w;
		double v;
		for(int i = 0; i < m; i++) {
			scanf("%d%lf", &w, &v);
			for(int j = n; j >= w; j--) {
				f[j] = max(f[j], 1 - (1-f[j-w]) * (1-v));
			}
		}
		printf("%.1lf%%\n", f[n]*100);
	}
	return 0;
}
