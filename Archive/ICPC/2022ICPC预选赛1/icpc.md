# ICPC 2022 网络赛部分题解

照例水个题解。这次A出5道题（ACDHL），rank200+，虽然说不上好不过也还行qwq。

## Index

因为并不是所有题都是我写的，所以只放这几题（点击跳到对应题解）：

- [Problem L](#l)
- [Problem D](#d)
- [Problem A](#a)

## L

比较有趣的是，这题几乎是我们队的签到题。说几乎是因为手慢被队友的C抢先了。

### 题意

给定两个字符串$S,T$ ，在$S$中找到一个最长的子序列$s$，满足$s$和$T$的最长公共子序列长度小于等于$1$。

注意是子序列而不是子串，即不要求连续。为了方便描述，下面都吧最长公共子序列称作$lcs$。

### 思路

我们可以得出几个结论。

#### $T$中没有的字符我们可以在$S$中全选

因为无论如何这些字符都不会增加$s$和$T$的公共子序列长度，我们直接贪心地全选即可。

#### 如果$T$存在两个相同的字符$\alpha$，那么我们至多在$S$中选择一个$\alpha$

否则$s$与$T$的$lcs$长度必定超过$1$。

#### 如果$T$中存在多个相同的字符$\alpha$，则$\alpha$和两辆相邻的$\alpha$之间所包含的字符相冲突

这是最重要的结论。考虑一个字符串：$...abcdaxyza...$，则$a$与字符$bcdxyz$均存在冲突，即如果选了$a$，那么这些字符都不能选择，否则一定会有$|lcs|\geq 2$。

根据这个结论，我们可以把$T$串看作若干个线段（端点为一个字符最前和最后出现的位置）：

![](L.png)

问题转化为，**选择尽可能多的线段，使得线段之间两两不相交**。当然选择必须要合法，即$S$中必须要有这个字符。另外，线段的规模就等于字符集的大小，即$\mathcal{O}(|\Sigma|)$。

---

下面考虑使用$dp$来解决这个问题。

#### 状态表示

$dp[i][j]$表示考虑到$S_i$字符，匹配到至多$j$线段位置的最大长度。

#### 状态转移

类似01背包，每个线段只有两种决策：拿和不拿，枚举决策即可。

- 不拿$S_i$ $dp[i][j]\leftarrow dp[i-1][j]$
- 后缀和 $dp[i][j]\leftarrow dp[i][j+1]$
- 拿$S_i$，假设$S_i$对应线段$[j,r]$ $dp[i][j]\leftarrow dp[i-1][r]$ （注意是反向拿线段）

#### 时间复杂度

$S$的长度乘上字符集大小，$\mathcal{O}(|S||\Sigma|)$。

### 实现

需要对线段端点离散化。

```cpp
using PII=pair<int,int>;
constexpr int N=5e5+10,M=26*2+5;
int dp[N][M];
bool mark[M];
PII pos[M];

void solve() {
    string s,t;
    cin>>s>>t;
    s=" "+s;
    t=" "+t;
    for(int i=1;i<t.size();i++) {
        int c=t[i]-'a';
        if(!mark[c]) mark[c]=1,pos[c]={i,i};
        else pos[c].second=i;
    }

    vector<int> num;
    for(int i=0;i<26;i++) 
        if(pos[i].first) {
            num.push_back(pos[i].first);
            num.push_back(pos[i].second);
        }

    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=0;i<26;i++)
        if(pos[i].first) {
            pos[i].first=lower_bound(num.begin(),num.end(),pos[i].first)-num.begin()+1;
            pos[i].second=lower_bound(num.begin(),num.end(),pos[i].second)-num.begin()+1;
        }

    int cnt=num.size();
    for(int i=1;i<s.size();i++) {
        int c=s[i]-'a';
        for(int j=cnt;j>=1;j--) {
            if(!mark[c]) dp[i][j]=dp[i-1][j]+1;
            else {
                dp[i][j]=dp[i-1][j];
                if(j<=pos[c].first) dp[i][j]=max(dp[i][j],dp[i-1][pos[c].second]+1);
            }
            dp[i][j]=max(dp[i][j],dp[i][j+1]);
        }
    }
    
    cout<<dp[s.size()-1][1];
}
```

## D

### 题意

定义一个二进制数$x$是好的，当$x$的后导$0$数量等于$x$中$1$的数量。例如$10100_2$就是好的。

有$T$组询问，每次询问$[l,r]$区间，输出任意一个好数，如果不存在就输出$-1$。

### 思路

这题还是可以用$dp$解决，似乎有更简单的做法不过我当时只写了$dp$。

#### 状态表示

$dp[0/1][0/1][i][j]$ 表示考虑前$i$位，$1$的数量为$j$，当前是否等于$l/r$的某个方案。

#### 状态转移

$$dp[0/1][0/1][i][j]\leftarrow dp[0/1][0/1][i-1][j-0/1]$$

对于每种状态，枚举决策即可，即选$0$还是选$1$，注意不能从非法的状态转移过来，例如突破了$l,r$的界限。$dp$完之后，枚举尾巴再拼接上dp的方案即可。

实际上这种写法细节比较多：

- 我们需要尽可能地让$dp$存的方案为奇数，否则会导致方案非法，因为枚举尾巴隐含了前一位是$1$。
- 拼接尾巴的时候，可能突破$l$的限制（$r$则不会）。例如$l=1110100_2$尾巴是$000_2$，那么前缀就不能是$1110_2$，这点需要特判。

#### 时间复杂度

$\mathcal{O}(T\log^2r)$

### 实现

```cpp
void solve() {
    int l,r,bak;
    cin>>l>>r;
    bak=l;
    vector<int> L,R;
    while(l) L.push_back(l&1),l>>=1;
    while(r) R.push_back(r&1),r>>=1;
    while(L.size()<R.size()) L.push_back(0);
    reverse(L.begin(),L.end());
    reverse(R.begin(),R.end());

    memset(dp,-1,sizeof dp);
    if(L.front()==R.front()) 
        dp[1][1][0][L.front()]=L.front();
    else {
        dp[0][1][0][R.front()]=R.front();
        dp[1][0][0][L.front()]=L.front();
    }

    auto update=[](int x,int &y,int v) {
        if(x!=-1&&(y==-1||(y&1)==0)) y=x<<1|v;
    };

    for(int bit=0;bit<L.size()-1;bit++) {
        int l=L[bit+1],r=R[bit+1];
        for(int cnt=0;cnt<=bit+1;cnt++) {
            // dp[0][0]
            update(dp[0][0][bit][cnt],dp[0][0][bit+1][cnt],0);
            update(dp[0][0][bit][cnt],dp[0][0][bit+1][cnt+1],1);
            
            // dp[0][1]
            update(dp[0][1][bit][cnt],dp[0][0==r][bit+1][cnt],0);
            if(r==1) update(dp[0][1][bit][cnt],dp[0][1==r][bit+1][cnt+1],1);

            // dp[1][0]
            if(l==0) update(dp[1][0][bit][cnt],dp[0==l][0][bit+1][cnt],0);
            update(dp[1][0][bit][cnt],dp[1==l][0][bit+1][cnt+1],1);
            
            // dp[1][1]
            if(l==0) update(dp[1][1][bit][cnt],dp[0==l][0==r][bit+1][cnt],0);
            if(r==1) update(dp[1][1][bit][cnt],dp[1==l][1==r][bit+1][cnt+1],1);
        }
    }

    bool flag=0;
    for(int len=1;len*2<=L.size();len++) {
        int bit=L.size()-len-1;
        flag|=bak&(1<<(len-1));
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++) {
                if(i&&flag) continue;
                int x=dp[i][j][bit][len];
                if(x!=-1&&(x&1)) {
                    cout<<(x<<len)<<endl;
                    return;
                }
            }
    }
    cout<<-1<<endl;
}
```

## A

是江莉出的题！可惜这题并不是我写的 ~~（那个时候我正忙着WA D）~~，感觉队友一直在讨论玄学的假做法（即只讲结论不讲证明），没想到后面居然过了 qwq。

### 题意

给定一个$01$环，每次可以选一个$1$，把以它为中心的三个数删掉，然后连起来。你可以进行$flip$操作，每次可以把一个数翻转。问最少的$flip$次数能把环删干净。多组询问。

### 思路

这题就很CF，给人的感觉就是暴力能消就消一定最优，考虑贪心。

设贡献为能消除的0的数量，计算每段连续的1的贡献，考虑两种基本情况：

- $...010...$ 此时贡献为2
- $...0110...$ 此时贡献为1

如果将上述两种情况多加上两个1，那么贡献都会加1。我们可以得到一个结论：

**如果环的贡献值超过了0的数量，那么一定存在一种顺序使得我们能消完整个环，否则我们可以贪心地进行$flip$。**

*一种顺序* 指的就是我们每次找最长的连续0区间，每次消这个区间两边的1，这样总是能使得我们的贡献值利用率最大化（$100\%$）。考虑贡献被浪费的情况，那么一定是某次消除导致了两段1合并，导致原本能消0的1被迫只能消另外的1。那么什么时候会出现这种情况呢？根据我们消除的顺序，一定是最长的0段长度等于1,那么此时说明**此时的局面一定形如$...010101...$**，而此时我们**即使浪费了贡献，我们也能消完整个环**。

根据这个结论，暴力能消就消然后贪心$flip$再消即可。统计前缀和之后，我们可以很容易地计算出最少的操作次数。

#### 时间复杂度

$\mathcal{O}(n+Q)$

### 实现

队友的代码。这题似乎有很多群友写的线段树，感觉很厉害。

```cpp
ll s[N];
int lc[N],rc[N];//往左连续1的数量，往右连续1的数量
int lid[N],rid[N];//往左第一个0的位置，往右第一个到0的位置
char str[N];
int a[N];
int g[N];

int f(int n)
{
    if(n%2==0) return n/2;
    else return (n-1)/2+2;
}
int main()
{
    int n,Q;
    scanf("%d%d",&n,&Q);
    scanf("%s",str+1);
    for(int i=1;i<=n;i++) a[i]=str[i]-'0';

    rid[n+1]=n+1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
        {
            lc[i]=lc[i-1]+1;
            lid[i]=lid[i-1];
        }
        else
        {
            lc[i]=0;
            lid[i]=i;
        }
    }

    for(int i=n;i>=1;i--)
    {
        if(a[i]==1)
        {
            rc[i]=rc[i+1]+1;
            rid[i]=rid[i+1];
        }
        else
        {
            rc[i]=0;
            rid[i]=i;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(a[i]==1&&a[i+1]==0) s[i]=s[i-1]+f(lc[i]);
        else s[i]=s[i-1];
        if(a[i]==0) g[i]=g[i-1]+1;
        else g[i]=g[i-1];
    }
    while(Q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);

        int L=rid[l];
        int R=lid[r];
        ll num0=0;
        ll numl=0;
        ll numr=0;
        if(a[l]==1) numl+=rc[l];
        if(a[r]==1) numr+=lc[r];
        if(a[l]==a[r]&&a[l]==1)
        {
            num0+=f(numl+numr);
        }
        else if(a[l]!=a[r]&&(a[l]==1||a[r]==1))
        {
            num0+=f(numl)+f(numr);
        }

        if(L<R)
        {
            num0+=s[R]-s[L];
        }

        ll res=(g[r]-g[l-1])-num0;
        if(res<0) puts("0");
        else
        {
            printf("%lld\n",(res+2)/3);
        }
    }
}
```

---

下周还有一场icpc,希望不要翻车qwq。