#include <algorithm>
#include <iostream>
#include <set>
#include <string.h>
#include <vector>
using namespace std;
// #define debug(x) cout<<"[debug]"#x<<"="<<x<<endl
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const ld eps = 1e-8;
const int INF = 0x3f3f3f3f, mod = 998244353;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

const int N = 2000006;
int tr[N];
int lowbit(int x) { return x & -x; }
int query(int x) {
    int res = 0;
    while (x) {
        res += tr[x];
        x -= lowbit(x);
    }
    return res;
}
void add(int x, int c) {
    while (x < N) {
        tr[x] += c;
        x += lowbit(x);
    }
    return;
}
int ne[N]; // 下一个位置
int pv[N]; // 上一个位置
int n;
char s[N];
int a[N];
set<int> cnt[N];
int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
        a[i] = s[i] - '0';
    for (int i = 1; i < n; i++)
        ne[i] = i + 1;
    for (int i = 2; i <= n; i++)
        pv[i] = i - 1;
    for (int i = 1; i <= n; i++) {
        if (!a[i])
            continue;
        int val = 0;
        for (int j = 0; j < 20 && i + j <= n; j++) {
            val <<= 1;
            val |= a[i + j];
            cnt[val].insert(i);
        }
    }
    for (int q = 1; q <= n; q++) {
        if (cnt[q].empty()) {
            puts("-1 0");
        } else {
            int s = *cnt[q].begin();
            printf("%d %d\n", s - query(s), cnt[q].size());

            auto nb_add = [&](int s) {
                if (!a[s])
                    return;
                int ts = 20;
                int now = s;
                int val = 0;
                while (ts-- && now) {
                    val <<= 1;
                    val |= a[now];
                    cnt[val].insert(s);
                    now = ne[now];
                }
            };
            auto nb_era = [&](int s) {
                if (!a[s])
                    return;
                int ts = 20;
                int now = s;
                int val = 0;
                while (ts-- && now) {
                    val <<= 1;
                    val |= a[now];
                    cnt[val].erase(s);
                    now = ne[now];
                }
            };

            int len = __lg(q) + 1;
            int ts = len;
            int now = s;
            while (ts-- && now) // 删除字符串
            {
                nb_era(now);
                add(now, 1);
                now = ne[now];
            }

            int las = pv[s];
            int New = now;
            now = las;
            ts = 20;
            while (ts-- && now) // 删除前面的字符串
            {
                nb_era(now);
                now = pv[now];
            }
            if (las) {
                ne[las] = New;
                pv[New] = las;
            }

            now = las;
            ts = 20;
            while (ts-- && now) // 新增字符串
            {
                nb_add(now);
                now = pv[now];
            }
        }
    }
}

/*

开n个set存储每个串 在原串中的 左端点
用一个数组存每个串出现次数
用一个map模拟链表维护字符串 map<idx->char>
用一个树状数组维护删去的数量

- 查询：
    - 拿set的begin，在原串中是idx，log
    - 然后去树状中查，idx前面删了多少，log
- 删除：
    - 树状数组[l,r]区间暴力+1 总计 nlogn
    - 把map里面这段字符串拿出来，暴力删除出现位置，复杂度 20^2*log
    - 暴力加出现位置，复杂度 20^2*log

*/