#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
long long mod;
long long A[MAXN];
struct tnode
{
    long long sum[2], lazy[2];
    int l, r;
};
long long quickpow(long long x, long long y, long long MOD)
{
    long long ans = 1;
    while (y)
    {
        if (y & 1)
        {
            ans = (x * ans) % MOD;
        }
        x = (x * x) % MOD;
        y >>= 1;
    }
    return ans;
}
long long get_c(long long n, long long m, long long MOD)
{
    if (m == 0)return 1;
    m = min(m, n - m);
    long long up = 1, down = 1;
    for (int i = 1; i <= m; ++i)
    {
        up = (up * (n - i + 1)) % MOD;
        down = (down * i) % MOD;
    }
    return up * quickpow(down, MOD - 2, MOD) % MOD;
}
long long lucas(long long n, long long m, long long MOD)
{
    if (m == 0)return 1;
    return get_c(n % MOD, m % MOD, MOD) * lucas(n / MOD, m / MOD, MOD);
}
tnode operator + (const tnode &A, const tnode &B)
{
    tnode C;
    C.l = A.l;
    C.r = B.r;
    C.lazy[0] = 1;
    C.lazy[1] = 0;
    C.sum[0] = A.sum[0] + B.sum[0];
    if (C.sum[0] >= mod)C.sum[0] -= mod;
    C.sum[1] = A.sum[1] + B.sum[1];
    if (C.sum[1] >= mod)C.sum[1] -= mod;
    C.sum[1] += A.sum[0] * B.sum[0] % mod;
    if (C.sum[1] >= mod)C.sum[1] -= mod;
    return C;
}
struct Segment_Tree
{
    tnode t[4 * MAXN];
    void init_lazy(int root)
    {
        t[root].lazy[0] = 1;
        t[root].lazy[1] = 0;
    }
    void union_lazy(int fa, int ch)
    {
        long long temp[2];
        temp[0] = t[fa].lazy[0] * t[ch].lazy[0] % mod;
        temp[1] = ((t[fa].lazy[0] * t[ch].lazy[1] % mod) + t[fa].lazy[1]) % mod;
        t[ch].lazy[0] = temp[0];
        t[ch].lazy[1] = temp[1];
    }
    void cal_lazy(int root)
    {
        long long len = (t[root].r - t[root].l + 1) % mod;
        if (mod != 2)
        {
            t[root].sum[1] = (len * (len - 1) / 2 % mod * t[root].lazy[1] % mod * t[root].lazy[1] % mod +
                              t[root].lazy[0] * t[root].lazy[0] % mod * t[root].sum[1] % mod +
                              t[root].lazy[0] * t[root].lazy[1] % mod * (len - 1) % mod * t[root].sum[0] % mod) % mod;
        }
        else
        {
            t[root].sum[1] = (lucas(len, 2, 2) % mod * t[root].lazy[1] % mod * t[root].lazy[1] % mod +
                              t[root].lazy[0] * t[root].lazy[0] % mod * t[root].sum[1] % mod +
                              t[root].lazy[0] * t[root].lazy[1] % mod * (len - 1) % mod * t[root].sum[0] % mod) % mod;
        }
        t[root].sum[0] = (len * t[root].lazy[1] % mod +
                          t[root].lazy[0] * t[root].sum[0] % mod) % mod;
        return;
    }
    void push_down(int root)
    {
        if (t[root].lazy[0] != 1 || t[root].lazy[1] != 0)
        {
            cal_lazy(root);
            if (t[root].l != t[root].r)
            {
                int ch = root << 1;
                union_lazy(root, ch);
                union_lazy(root, ch + 1);
            }
            init_lazy(root);
        }
    }
    void update (int root)
    {
        int ch = root << 1;
        push_down(ch);
        push_down(ch + 1);
        t[root] = t[ch] + t[ch + 1];
    }
    void build(int root, int l, int r)
    {
        t[root].l = l;
        t[root].r = r;
        init_lazy(root);
        if (l != r)
        {
            int mid = (l + r) >> 1;
            int ch = root << 1;
            build(ch, l, mid);
            build(ch + 1, mid + 1, r);
            update(root);
        }
        else
        {
            t[root].sum[0] = A[l] % mod;
            t[root].sum[1] = 0;
        }
    }
    void change(int root, int l, int r, long long delta, int op)
    {
        push_down(root);
        if (l == t[root].l && r == t[root].r)
        {
            t[root].lazy[op] = delta % mod;
            return;
        }
        int mid = (t[root].l + t[root].r) >> 1;
        int ch = root << 1;
        if (r <= mid)change(ch, l, r, delta, op);
        else if (l > mid)change(ch + 1, l, r, delta, op);
        else {change(ch, l, mid, delta, op); change(ch + 1, mid + 1, r, delta, op);}
        update(root);
    }
    tnode sum(int root, int l, int r)
    {
        push_down(root);
        if (t[root].l == l && t[root].r == r)
        {
            return t[root];
        }
        int mid = (t[root].l + t[root].r) >> 1;
        int ch = root << 1;
        if (r <= mid)return sum(ch, l, r);
        else if (l > mid)return sum(ch + 1, l, r);
        else return sum(ch, l, mid) + sum(ch + 1, mid + 1, r);
    }
};
Segment_Tree ST;
int n, m, op, l, r, T;
long long x;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %lld", &n, &m , &mod);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld", &A[i]);
        }
        ST.build(1, 1, n);
        for (int _ = 1; _ <= m; ++_)
        {
            scanf("%d %d %d", &op, &l, &r);
            if (op <= 2)
            {
                scanf("%lld", &x);
                ST.change(1, l, r, x, 2 - op);
            }
            else
            {
                printf("%lld\n", ST.sum(1, l, r).sum[1]);
            }
        }
    }
    return 0;
}
