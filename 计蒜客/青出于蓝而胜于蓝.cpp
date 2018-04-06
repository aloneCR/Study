#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define lowbit(x) (x&-x)
const int maxn = 100000 + 5;
int c[maxn*2];
int l[maxn], r[maxn], times; //时间戳
int n, p;
vector<int> G[maxn];

void dfs(int u, int pre) {
	l[u] = ++times;
	for(int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if(v != pre) {
			dfs(v, u);
		}
	}
	r[u] = times;
}

void update(int x, int d) {
	while(x <= n) {
		c[x] += d;
		x += lowbit(x);
	}
}

int sum(int x) {
	int ret = 0;
	while(x > 0) {
		ret += c[x];
		x -= lowbit(x);
	}
	return ret;
}

int main() {
	while(scanf("%d%d", &n, &p) == 2) {
		int u, v;
		for(int i = 0; i < n-1; i++) {
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		times = 0;
		dfs(p, -1);
		for(int i = 1; i <= n; i++) {
			printf("%d%c", sum(r[i]) - sum(l[i]), i==n?'\n':' ');
			update(l[i], 1);
		}
	}
	return 0;
}
