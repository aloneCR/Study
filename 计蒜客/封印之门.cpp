#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1000 + 5;
char a[maxn], b[maxn];
vector<int> G[26];
int vis[maxn];

void init() {
    for(int i = 0; i < 26; i++) G[i].clear();
}

int bfs(int s, int e) {
    memset(vis, -1, sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s] = 0;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        if(x == e) {
            return vis[e];
        }
        for(int i = 0; i < G[x].size(); i++) {
            int y = G[x][i];
            if(vis[y] == -1) {
                vis[y] = vis[x] + 1;
                q.push(y);
            }
        }
    }
    return -1;
}

int main() {
    while(scanf("%s%s", a, b) == 2) {
        init();
        int k;
        scanf("%d", &k);
        char x, y;
        for(int i = 0; i < k; i++) {
            getchar();
            scanf("%c %c", &x, &y);
            G[x-'a'].push_back(y-'a');
        }
        int flag = 1, tol = 0;
        for(int i = 0; a[i] != '\0'; i++) {
            int step = bfs(a[i] - 'a', b[i] - 'a');
            if(step == -1) {
                flag = 0;
                break;
            }
            else tol += step;
        }
        if(flag) printf("%d\n", tol);
        else printf("-1\n");
    }
    return 0;
}