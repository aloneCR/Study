#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 5;
map<string, int> ID;
int id;
vector<int> G[maxn];
int dp[maxn][2];	//是否邀请编号为i的员工
int uniq[maxn][2];	//0表示不唯一 1表示唯一
void init(int n) {
	id = 0;
	ID.clear();
	for(int i = 0; i < n; i++) G[i].clear();
}

int getID(string &s) {
	if(!ID.count(s)) ID[s] = id++;
	return ID[s];
}

int solve(int u, int f) {
	if(dp[u][f] != -1) return dp[u][f];
	dp[u][f] = f;
	uniq[u][f] = 1;
	for(int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if(f) {
			dp[u][f] += solve(v, 0);
			if(uniq[v][0] == 0) uniq[u][f] = 0;
		} else {
			dp[u][f] += max(solve(v, 0), solve(v, 1));
			if(dp[v][0] == dp[v][1]) {
				uniq[u][f] = 0;
			}
			if(dp[v][0] > dp[v][1] && uniq[v][0] == 0) {
				uniq[u][f] = 0;
			} 
			if(dp[v][1] > dp[v][0] && uniq[v][1] == 0) {
				uniq[u][f] = 0;
			}
		}
	}
	return dp[u][f];
}

int main() {
	int n;
	string a, b, boss;
	while(scanf("%d", &n) == 1 && n) {
		init(n);
		cin >> boss;
		ID[boss] = id++;
		for(int i = 0; i < n-1; i++) {
			cin >> a >> b;
			int x = getID(a), y = getID(b);
			G[y].push_back(x);
		}
		memset(dp, -1, sizeof(dp));
		printf("%d ", max(solve(0, 0), solve(0, 1)));
		int f = true;
		if(dp[0][0] == dp[0][1]) f = false;
		if(dp[0][0] > dp[0][1] && uniq[0][0] == 0) f = false;
		if(dp[0][1] > dp[0][0] && uniq[0][1] == 0) f = false;
		printf("%s\n", f?"Yes":"No");
	}
	return 0;
}
