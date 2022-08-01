#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int maxn = 5000000 + 5;
using LL=long long;

namespace pam {
int sz, tot, last;
LL cnt[maxn];
int ch[maxn][26], len[maxn], fail[maxn];
char s[maxn];

int new_node(int l) { // 建立一个新节点，长度为 l
    sz++;
    memset(ch[sz], 0, sizeof(ch[sz]));
    len[sz] = l;
    fail[sz] = cnt[sz] = 0;
    return sz;
}

void clear() { // 初始化
    sz = -1;
    last = 0;
    s[tot = 0] = '$';
    new_node(0);
    new_node(-1);
    fail[0] = 1;
}

int getfail(int x) { // 找后缀回文
    while (s[tot - len[x] - 1] != s[tot])
        x = fail[x];
    return x;
}

void insert(char c) { // 建树
    s[++tot] = c;
    int now = getfail(last);
    if (!ch[now][c - 'a']) {
        int x = new_node(len[now] + 2);
        fail[x] = ch[getfail(fail[now])][c - 'a'];
        ch[now][c - 'a'] = x;
    }
    last = ch[now][c - 'a'];
    cnt[last]++;
}

void solve() {
    LL ans1 = 0;
    LL ans2 = 0;
    LL ans3 = 0;
    for (int i = sz; i >= 0; i--) {
        cnt[fail[i]] += cnt[i];
    }
    for(int i=0;i<=sz;i++) {
        if(ch[i]['k'-'a']>=1) ans1+=cnt[ch[i]['k'-'a']];
        if(ch[i]['f'-'a']>=1) ans2+=cnt[ch[i]['f'-'a']];
        if(ch[i]['c'-'a']>=1) ans3+=cnt[ch[i]['c'-'a']];
    }
    printf("%lld %lld %lld\n",ans1,ans2,ans3);
}
} // namespace pam

char s[maxn];

int main() {
    int n;
    while(cin>>n) {
        pam::clear();
        for(int i=1;i<=n;i++) cin>>s[i];
        for(int i=1;i<=n;i++) pam::insert(s[i]);
        pam::solve();
    }
    return 0;
}
