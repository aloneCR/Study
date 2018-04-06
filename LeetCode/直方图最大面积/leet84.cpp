#define LOCAL
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 5;

int largestRectangleArea(vector<int>& heights) {
	int maxRect = 0, n = heights.size();
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
	int n;
	while(scanf("%d", &n) == 1) {
		int h;
		vector<int> heights;
		for(int i = 0; i < n; i++) {
			scanf("%d", &h);
			heights.push_back(h);
		}
		printf("%d\n", largestRectangleArea(heights));
	}
	return 0;
}
