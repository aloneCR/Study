#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int, int> Pii;
const int maxn = 50000 + 5; 

struct SegmentTree {
	int maxv, minv;
}t[maxn<<2];

void update(int cur) {
	int lc = cur*2, rc = cur*2+1;
	t[cur].maxv = max(t[lc].maxv, t[rc].maxv);
	t[cur].minv = min(t[lc].minv, t[rc].minv);
}

void buildTree(int cur, int l, int r) {
	if(l == r) {
		scanf("%d", &t[cur].maxv);
		t[cur].minv = t[cur].maxv;
		return;
	}
	buildTree(cur*2, l, (l+r)/2);
	buildTree(cur*2+1, (l+r)/2+1, r);
	update(cur);
}

int ql, qr;
Pii query(int cur, int l, int r) {
	int m = (l+r) / 2;
	if(ql <= l && r <= qr) {
		return Pii(t[cur].maxv, t[cur].minv);
	}
	Pii p = Pii(0, INF);
	if(ql <= m) { 	//Ïò×ó 
		Pii a = query(cur*2, l, m);
		p.first = max(p.first, a.first);
		p.second = min(p.second, a.second);
	}
	if(m < qr) {	//ÏòÓÒ 
		Pii a = query(cur*2+1, m+1, r);
		p.first = max(p.first, a.first);
		p.second = min(p.second, a.second);
	}
	return p;
}

int main() {
	int n, q;
	while(scanf("%d%d", &n, &q) == 2) {
		buildTree(1, 1, n);
		for(int i = 0; i < q; i++) {
			scanf("%d%d", &ql, &qr);
			Pii p = query(1, 1, n);
			printf("%d\n", p.first - p.second);
		}
	}
	return 0;
}
