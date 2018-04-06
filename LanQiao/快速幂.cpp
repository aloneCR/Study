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

int pow_mod(int a, int n, int m) {
    if(n == 0) return 1;
    int x = pow_mod(a, n/2, m);
    LL ans = (LL)x * x % m;
    if(n & 1) ans = ans * a % m;
    return (int)ans;
}

int main() {
    printf("%d\n", pow_mod(2, 5, 5));
    return 0;
}