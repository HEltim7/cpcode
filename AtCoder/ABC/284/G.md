# ABC 284 Problem G Only Once

$b$数组可以看作一个链套环的图，贡献为链长，转化为排列组合问题，考虑枚举环大小$k$和链长$l$，分部考虑：

- 环的方案数 $\binom{n}{k}k!$
- 链的方案数 $\binom{n-k}{l}l!$
- 剩下的任选 $n^{n-k-l}$
- 贡献就等于 $l$

合起来答案就是：

$$
ans=\sum_{k=1}^{n}{\sum_{l=0}^{n-k}{\binom{n}{k}k!\binom{n-k}{l}l!n^{n-k-l}l}}
$$

发现要求这个东西是$\mathcal{O}(n^2)$的，而且给的模数还不保证是质数，考虑进一步转化柿子。

$$
\begin{split}
原式 & =\binom{n}{k}k!\binom{n-k}{l}l!n^{n-k-l}l \\
& = \frac{n!}{k!(n-k)!}k! \frac{(n-k)!}{l!(n-k-k)!}l! n^{n-k-l}l \\
& = \frac{n!}{n-k-l}n^{n-k-l}l \\
& = \prod_{i=0}^{k+l-1}{n-i} \cdot n^{n-k-l}l
\end{split}
$$

不妨令$j=k+l$，答案就等于：

$$
ans=\sum_{l=0}^{n-1}{\sum_{j=l+1}^{n}{\prod_{i=0}^{j-1}{n-i} \cdot n^{n-j}l}}
$$

此时我们成功的将$k$和$l$解耦，可以发现这个柿子的前半部分($\prod_{i=0}^{j-1}{n-i} \cdot n^{n-j}$)只含$j$这一个变量，我们可以预处理出这部分的前缀和，然后再枚举$l$即可将复杂度降为线性。

时间复杂度$\mathcal{O}(n)$。

```cpp
constexpr int N=2e5+10;
Mint pw[N],pre1[N],pre2[N];

void init(int n) {
    pw[0]=1;
    for(int i=1;i<=n;i++) pw[i]=pw[i-1]*n;
    pre1[1]=n;
    for(int i=2;i<=n;i++) pre1[i]=pre1[i-1]*(n-i+1);
    for(int i=2;i<=n;i++) pre2[i]=pre2[i-1]+pre1[i]*pw[n-i];
}

void solve() {
    int n;
    cin>>n>>mod;
    init(n);

    Mint ans;
    for(int l=1;l<n;l++) ans+=(pre2[n]-pre2[l])*l;
    cout<<ans;
}
```