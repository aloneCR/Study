#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 5;
int a[maxn], b[maxn];
int main() {
	int n;
	while(scanf("%d", &n) == 1) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		b[n-1] = a[n-1];
		for(int i = n-2; i >= 0; i--) {
			b[i] = max(a[i], b[i+1]);
		}
		stack<int> S;
		vector<int> ans;
		for(int i = 0; i < n;) {
			if(S.empty() || S.top() < b[i]) {
				S.push(a[i]);
				++i;
			} else {
				ans.push_back(S.top());
				S.pop();
			}
		}
		while(!S.empty()) {
			ans.push_back(S.top());
			S.pop();
		}
		for(int i = 0; i < n; i++) {
			printf("%d%c", ans[i], i==n-1?'\n':' ');
		}
	}
	return 0;
}
