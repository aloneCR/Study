#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 100 + 5;
char s[maxn], f[maxn];
const char c[] = {'A', 'B', 'C'};

int ppp(char *s) {
    int n = strlen(s);
    int tol = 0, flag = 1;
    while(flag) {
        flag = tol = 0;
        for(int i = 0; i < n; i++) {
            int same = 0, j = i;
            char ch = s[i];
            while(j < n && s[j] == ch) {
                same++;
                j++;
            }
            if(same > 1) {
                i = j - 1;
                flag = 1;
            } else {
                s[tol++] = ch;
            }
        }
        n = tol;
        s[n] = '\0';
    }
    return tol;
}

void insert(char *s, char *f, int pos, char ch) {
    int n = strlen(s);
    int t = 0;
    for(int i = 0; i < pos; i++) f[t++] = s[i];
    f[t++] = ch;
    for(int i = pos; i < n; i++) f[t++] = s[i];
    f[t] = '\0';
}

int solve(char *s) {
    int ans = 0;
    int n = strlen(s);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            insert(s, f, i + 1, c[j]);
            ans = max(n + 1 - ppp(f), ans);
        }
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        printf("%d\n", solve(s));
    }
    return 0;
}
