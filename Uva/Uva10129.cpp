#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 5;
char s[maxn];
int par[26], in[26], out[26], vis[26];

int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}

int main() {
	int T, n;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 0; i < 26; i++) par[i] = i;
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; i++) {
			scanf("%s", s);
			int x = s[0] - 'a'; 
			int y = s[strlen(s)-1] - 'a';
			vis[x] = vis[y] = 1;
			in[y]++;
			out[x]++;
			int rx = find(x), ry = find(y);
			if(rx != ry) par[rx] = ry;
		}
		//判断是否联通
		int root = find(s[0]-'a');
		int flag = 1;
		for(int i = 0; i < 26; i++) {
			if(vis[i]) {
				if(find(i) != root) {
					flag = 0;
					break;
				}
			}
		}
		// 判断是否满足欧拉路径的条件
		if(flag) {
			int tol = 0, odd[2] = {0};
			for(int i = 0; i < 26; i++) {
				if(vis[i]) {
					//printf("%c %d %d\n", i+'a', in[i], out[i]);
					if(in[i] != out[i]) {
						if(tol + 1 > 2) {
							flag = 0;
							break;
						}
						odd[tol++] = in[i] - out[i];
					}
				}
			}
			if(tol == 1 || tol > 2) flag = 0;
			if(tol == 2 && flag) {
				if(odd[0] > odd[1]) swap(odd[0], odd[1]);
				if(odd[0] != -1 || odd[1] != 1) flag = 0;
			}
		}
		if(flag) printf("Ordering is possible.\n");
		else printf("The door cannot be opened.\n");
	}
	return 0;
}
