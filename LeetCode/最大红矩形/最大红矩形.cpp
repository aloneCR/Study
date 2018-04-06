#include <bits/stdc++.h>
using namespace std;
const int maxn = 1500 + 5;
int h[maxn];
char chess[maxn];

int largestRectangleArea(int heights[], int n) {
	int maxRect = 0;
	stack<int> S;
	for(int i = 0; i < n; ) {
		if(S.empty() || heights[S.top()] <= heights[i]) {
			S.push(i);
			++i;
		} else {
			int t = S.top(); S.pop();
			maxRect = max(maxRect, S.empty()?i*heights[t]:(i-S.top()-1)*heights[t]);
		}
	}
	while(!S.empty()) { //假想右侧有一个哨兵高度为0(卡位)
		int t = S.top(); S.pop();
		maxRect = max(maxRect, S.empty()?n*heights[t]:(n-1-S.top())*heights[t]);
	}
	return maxRect;
}


int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) == 2) {
		memset(h, 0, sizeof(h));
		int ans = 0;
		for(int i = 0; i < n; i++) {
			scanf("%s", chess);
			for(int j = 0; j < m; j++) {
				if(chess[j] == 'X') h[j] = 0;
				else h[j] = h[j] + 1;
			}
			ans = max(ans, largestRectangleArea(h, m));
		}
		printf("%d\n",ans);
	}
	return 0;
}
