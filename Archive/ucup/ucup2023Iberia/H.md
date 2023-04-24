# ucup stage 13 Iberia Problem H. Exact Subsequences

先正向考虑，对于一个01串如何快速计算有多少本质不同的子序列。

想像我们有一棵 $\text{01 Trie}$ 来保存所有的子序列，$\text{Trie}$ 刚开始仅有一个根节点，维护三个变量 $l,r,sum$ 分别表示没有左孩子的节点数量，没有右孩子的节点数量，总节点数。一开始只有一个根，表示空序列，此时 $l=1,r=1,sum=1$。

那么，每次在串后面加上一个0会新增 $l$ 个点：

- `sum+=l`
- `l=l`
- `r+=l`

加1新增 $r$ 个点：

- `sum+=r`
- `l+=r`
- `r=r`

观察转移过程，实际上并不需要保存 $sum$ ，因为 $sum$ 等于最后的 $l+r-1$，本质不同的子序列数为 $l+r-2$。

那么要满足 $n$ 个本质不同的子序列，就要求 $l+r-2=n$，即 $l+r=n+2$。

将树生长的过程逆过来，每次给定 $l,r$，树逆生长的过程是唯一确定的：

- 如果 $l<r$ 那么说明当前状态是前一个状态+0得到的。（否则，前一个状态 $l$ 只可能是负数，显然非法）
- 如果 $l>r$ 那么是前一个状态+1得到的
- $l=r$ 只有初始状态满足，其他情况非法，否则前一个状态必然存在 $l,r$ 中有一个是 $0$ 。

发现这个过程其实就是辗转相减法（更相减损术）。而初始状态 $l=r=1$，所以 一组 $(l,r)$ 是 $n$ 的解当且仅当 $gcd(l,r)=1$，否则树逆生长（即执行辗转相减法）时必定无法到达 $(1,1)$ 的状态。

观察到 $gcd(l,n+2)=gcd(l,n+2-l)=gcd(l,r)=1$。所以一组合法 $l,r$ 等价于 $l$ 和 $n+2$ 互质（此时 $r$ 也与 $n+2$ 互质）。因此合法的 $l$ 数量其实就是 $\varphi(n+2)$。

---

现在考虑如何处理第 $k$ 大。首先根据上面的结论，当 $k>\varphi(n+2)$ 时是无解的。观察最开始加字符的流程，可以发现每次将字符加到后面和每次将字符加到前面是一样的。因此我们可以将整个构造过程反转，这样处理的好处是，求 $gcd$ 还原字符串的过程便从反向变为了正向。

记一个状态 $(l,r)$ 得到的字符串为 $s(l,r)$，$s(l_1,r_1)=s_1,s(l_2,r_2)=s_2$。考虑两个状态 $(l_1,r_1),(l_2,r_2)$ ，假设 $l_1<l_2,r_1>r_2$，那么必然有 $s_1<s_2$。

**证明**

首先若 $l_2<r_2$，那么 $l_1<l_2<r_2<r_1$，即当 $s_2$ 以0开头时，$s_1$ 必然也以0开头，也就是说 $s_2$ 首字符必然不会比 $s_1$ 小。

若它们的首字符相等且均为0，即 $l<r$ 的情况，那么 $s_1=0+s(l_1,r_1-l_1),s_2=0+s(l_2,r_2-l_2)$ ，其中 $l_1<l_2,r_1-l_1>r_2-l_2$。

若它们的首字符相等且均为1，即 $l>r$ 的情况，那么 $s_1=1+s(l_1-r_1,r_1),s_2=1+(l_2-r_2,r_2)$，其中 $l_1-r_1<l_2-r,r_1<r_2$。

因此不管是那种情况，偏序关系总是保持为 $l_1<l_2,r_1>r_2$，递归这个过程，必定可以找到 $s_1$ 与 $s_2$ 第一个不同的位置 $x$，此时就变为了前面讨论的首字符不同的情况，也就是 $s_{1_x}=0,s_{2_x}=1$。因此 $s_1<s_2$。

因此第 $k$ 小的合法 $(l,r)$，必定满足 $l$ 也是第 $k$ 小的。

---

此时问题简化为，给定一个 $n,k$ 找到与 $n+2$ 互质的第 $k$ 个数。将这个数作为 $l$ 而 $r=n+2-l$，使用 $gcd$ 求解原串即可。

在 $\mathcal{O}(\sqrt n)$ 的时间内计算 $n+2$ 的质因数。二分答案，使用容斥计算前缀中与 $n+2$ 互质的数的数量即可。

```cpp
template<typename T> vector<T> get_prime_factor(T x) {
    vector<T> res;
    for(T i=2;i*i<=x;i++) {
        if(x%i==0) {
            while(x%i==0) x/=i;
            res.push_back(i);
        }
    }
    if(x>1) res.push_back(x);
    return res;
}

void solve() {
    int n,k;
    cin>>n>>k;
    auto &&num=get_prime_factor(n+2);
    
    auto count=[&](int x) {
        int pre=0;
        for(int i=1;i<1<<num.size();i++) {
            int sign=__builtin_popcount(i)&1?1:-1;
            int prod=1;
            for(int j=0;j<num.size();j++) {
                if(i>>j&1) prod*=num[j];
            }
            pre+=sign*x/prod;
        }
        return x-pre;
    };

    int tot=count(n+2);
    if(tot<k) {
        cout<<-1<<endl;
        return;
    }

    int L=1,R=n+1;
    while(L<R) {
        int mid=L+R>>1;
        if(count(mid)>=k) R=mid;
        else L=mid+1;
    }

    int l=L,r=n+2-l;
    bool front=l>r;
    vector<int> ans;
    
    while(l&&r) {
        assert(l!=r);
        if(l<r) swap(l,r);
        int t=l/r;
        l-=t*r;
        ans.emplace_back(t);
    }
    ans.back()--;
    cout<<ans.size()<<' '<<front<<endl;
    for(int x:ans) cout<<x<<' ';
    cout<<endl;
}
```