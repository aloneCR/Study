#include <stdio.h>
const int maxn = 100000 + 5;

struct SegmentTree{
	long long sum;
	long long inc;	
}t[maxn<<2];

void buildTree(int o, int l, int r) {
	t[o].inc = 0;
	if(l == r) {
		scanf("%lld", &t[o].sum);
		return;
	}
	int m = (l+r) / 2;
	buildTree(o*2, l, m);
	buildTree(o*2+1, m+1, r);
	t[o].sum = t[o*2].sum + t[o*2+1].sum;
}

void pushdown(int o, int l, int r) {
	int lc = o*2, rc = o*2+1;
	int m = (l+r) / 2;
	if(t[o].inc != 0) {	//卧槽,有负数的情况 
		long long c = t[o].inc;
		t[lc].sum += (m-l+1)*c;
		t[rc].sum += (r-m)*c;
		t[lc].inc += c;
		t[rc].inc += c;
		t[o].inc = 0;
	}
}

int ul, ur;
void update(int o, int l, int r, int c) {
	int m = (l+r) / 2;
	if(ul <= l && r <= ur) {
		t[o].sum += 1LL*(r-l+1)*c;
		t[o].inc += c;
		return;
	}
	pushdown(o, l, r);
	if(ul <= m) update(o*2, l, m, c);
	if(m < ur) update(o*2+1, m+1, r, c);
	t[o].sum = t[o*2].sum + t[o*2+1].sum;
}

int ql, qr;
long long query(int o, int l, int r) {
	int m = (l+r)/2;
	if(ql <= l && r <= qr) return t[o].sum;
	pushdown(o, l, r);
	long long ans = 0;
	if(ql <= m) ans += query(o*2, l, m);
	if(m < qr) ans += query(o*2+1, m+1, r);
	return ans;
}

int main() {
	int n, q, c;
	char cmd;
	while(scanf("%d%d", &n, &q) == 2) {
		buildTree(1, 1, n);
		for(int i = 0; i < q; i++) {
			getchar();
			scanf("%c", &cmd);
			if(cmd == 'Q') {
				scanf("%d%d", &ql, &qr);
				printf("%lld\n", query(1, 1, n));
			} else {
				scanf("%d%d%d", &ul, &ur, &c);
				update(1, 1, n, c);
			}
		}
	}
	return 0;
}
