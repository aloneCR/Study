//#define LOCAL
#include <stdio.h>
const int maxn = 1000 + 5;
int heap[maxn], order[maxn];
int m, n, time;

bool check(int a, int b, int f) {
	if(!f) return a <= b;
	else return a >= b;
}

bool isHeap(int f) { //f=0 min, f=1 max
	for(int i = 1; i <= n; i++) {
		int ok = 1;
		if(i*2 <= n) ok = check(heap[i], heap[i*2], f);
		if(!ok) return false;
		if(i*2+1 <= n) ok = check(heap[i], heap[i*2+1], f);
		if(!ok) return false;
	}
	return true;
}

void postOrder(int u) {
	if(u*2 <= n) postOrder(u*2);
	if(u*2+1 <= n) postOrder(u*2+1);
	order[++time] = heap[u];
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d\n", &m, &n);
	for(int i = 0; i < m; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &heap[j]);
		}
		if(isHeap(0)) printf("Min Heap\n");
		else if(isHeap(1)) printf("Max Heap\n");
		else printf("Not Heap\n");
		time = 0;
		postOrder(1);
		for(int j = 1; j <= n; j++) {
			printf("%d%c", order[j], j==n?'\n':' ');
		}
	}
	return 0;
}
