#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
typedef long long LL;
const int maxn = 15 + 5;
char pre[maxn], goal[maxn];
int n;
map<LL, int> mp;
char a[maxn];
const int d[] = { -1, -2, -3, 1, 2, 3};

LL encode(const char s[]) {
    LL res = 0, bit = 1;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'W') res += bit;
        else if(s[i] == '*') res += 2 * bit;
        bit *= 3;
    }
    return res;
}

int decode(LL code, char s[]) {
    int pos = 0;
    for(int i = 0; i < n; i++) {
        int r = code % 3;
        if(r == 0) s[i] = 'B';
        else if(r == 1) s[i] = 'W';
        else {
            s[i] = '*';
            pos = i;
        }
        code /= 3;
    }
    s[n] = '\0';
    return pos;
}

int bfs() {
    mp.clear();
    queue<LL> Q;
    LL code = encode(pre);
    mp[code] = 0;
    Q.push(code);
    while(!Q.empty()) {
        code = Q.front();
        Q.pop();
        int step = mp[code];
        int pos = decode(code, a);
        //printf("%s\n", a);
        if(!strcmp(a, goal)) {
            return step;
        }
        for(int i = 0; i < 6; i++) {
            int j = pos + d[i];
            if(j >= 0 && j < n) {
                swap(a[pos], a[j]);
                code = encode(a);
                if(!mp.count(code)) {
                    mp[code] = step + 1;
                    Q.push(code);
                }
                swap(a[pos], a[j]);
            }
        }
    }
    return -1;
}

int main() {
    while(scanf("%s%s", pre, goal) == 2) {
        n = strlen(pre);
        printf("%d\n", bfs());
    }
    return 0;
}