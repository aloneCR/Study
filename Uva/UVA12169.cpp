// slow solution
#include <stdio.h>
#include <algorithm>
using namespace std;
#define M 10001
const int maxn = 200 + 5;
int x[maxn];
int a, b, n;
void solve() {
    for(a = 0; a <= M; a++)
        for(b = 0; b <= M; b++) {
            bool flag = true;
            for(int i = 2; i <= 2*n; i+=2) {
                x[i] = (a * x[i-1] + b) % M;
                if(i+1 <= 2*n && x[i+1] != (a * x[i] + b) % M) {
                    flag = false;
                    break;
                } 
            }
            if(flag) return;
        }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= 2 * n; i += 2) {
        scanf("%d", &x[i]);
    }
    solve();
    for(int i = 2; i <= 2*n; i+=2) {
        printf("%d\n", x[i]);
    }
    return 0;
}