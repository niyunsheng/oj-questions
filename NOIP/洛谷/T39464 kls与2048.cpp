/*
kls与2048

#### 30分做法
由于$n$只有10，可以爆搜，复杂度是卡特兰数级别（二叉树数量）。
#### 60分做法
考虑这样一种贪心：每次选择最小的两个数字，设最小为$x$，次小为$y$。
*   如果$2x \le y$，那么就把$x$丢弃（之后就不管了）；
*   如果$2x &gt; y$， 就把$y$减小到$x$，然后把它们组合成$2x$。
不断重复这个操作，直到只剩一个数，就是答案。
可以使用一个堆（优先队列）来维护最小数，总复杂度$O(n\log n)$。
#### 100分做法
由于$n$达到了$10^7$的级别，需要一个$O(n)$的算法。考虑在60分做法的基础上进行优化。
与[合并果子](https://www.luogu.org/problemnew/show/P1090)、[NOIP2016 蚯蚓](https://www.luogu.org/problemnew/show/P2827)类似，可以观察到一个性质：按照上面的方法，每次合成出来的数字大小是不断增加的。
于是可以用一个队列来维护合成出来的数字，每次的最小值只可能在队头取到。
然后将原数列进行桶排序，每次在排序后的数列和队列中取最小值，就可以做到$O(n)$的总复杂度了。
*/
```
#include <cstdio>

typedef long long ll;
const int MAXN = 1e7 + 5, INF = 0x3f3f3f3f;

int n, m, s, cur, fr, re;
int a[MAXN], c[MAXN];
ll q[MAXN];

void generate_array(int a[], int n, int m, int seed) {
    unsigned x = seed;
    for (int i = 0; i < n; ++i) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        a[i] = x % m + 1;
    }
}

ll getmin() {
    if (cur == n) return q[fr++];
    if (fr == re || a[cur] < q[fr]) return a[cur++];
    return q[fr++];
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    generate_array(a, n, m, s);
    for (int i = 0; i < n; ++i) c[a[i]]++;

    n = 0;
    for (int i = 1; i <= m; ++i) {
        for (; c[i]; c[i]--) a[n++] = i;
    }

    cur = 0;
    for (int i = 1; i <= n - 1; ++i) {
        ll x = getmin(), y = getmin();
        if (y < x + x) q[re++] = x + x;
        else a[--cur] = y;
    }
    printf("%lld\n", getmin());
}
```
