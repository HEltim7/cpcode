# ARC 153 Problem C ± Increasing Sequence

[AtCoder](https://atcoder.jp/contests/arc153/tasks/arc153_c)

构造题，一种朴素的思路是，先随便构造出一个序列，然后对其做适当的偏移使得它合法。

不妨先假设$A$序列中的1与-1数量不同（记这个差值为$cnt$）。可以证明此时必定有解。

设$A$的后缀和为$suf$，显然$suf$至少存在一个1或者-1。不妨假设存在$suf_{i}=1$，那么如果我们能够构造答案序列$ans$，使得其和$sum$为负数，那么我们就可以将$ans$的$i$后缀整体加上$|sum|$，来使得整个序列的和为0。

满足上述要求的序列同样是必定存在的，我们可以先随便设一个最简单的初始序列$ans=[1,2,3...n]$，那么因为1的数量与-1不同，即我们将整个序列+1或者-1时，其$sum$必然会变成$sum \pm cnt$，于是我们只要偏移$\pm \lceil \frac{|sum|}{|cnt|} \rceil$后就可以得到和为负（正）的$ans$序列了。

所以当$|cnt|>0$时，必定有解。现在考虑$cnt=0$的情况，此时$ans$序列通过整体偏移必定是无效果的，假设$sum>0$那么如果$suf$不存在-1，那么必定无解因为我们无论怎么操作，都不能找到一个位置让$sum$变小，$sum<0$的情况也是类似的。而对于可以造成无解的局面，其$sum$必定始终为正或始终为负，否则一定存在一种方法，通过上述的步骤使其符号取反，因此这是充分必要的（这里讲的比较粗略，你可以模拟几组样例来理解和验证）。

时间复杂度$\mathcal{O}(n)$。

```cpp
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N],suf[N];
LL ans[N];

void solve() {
    int n,idxP=0,idxN=0,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=n;i>=1;i--) {
        suf[i]=suf[i+1]+arr[i];
        if(arr[i]==1) cnt++; else cnt--;
        if(suf[i]==1) idxP=i;
        if(suf[i]==-1) idxN=i;
    }

    LL sum=0;
    int idx=0;
    for(int i=1;i<=n;i++) ans[i]=i,sum+=arr[i]*ans[i];
    if(cnt==0&&((sum>0&&!idxN)||(sum<0&&!idxP))) cout<<"No"<<endl;
    else {
        cout<<"Yes"<<endl;
        if((sum>0&&!idxN)||(sum<0&&!idxP)) {
            LL t=(abs(sum)+abs(cnt)-1)/abs(cnt);
            if(sum*cnt>=0) for(int i=1;i<=n;i++) ans[i]-=t;
            else for(int i=1;i<=n;i++) ans[i]+=t;
        }

        sum=0;
        for(int i=1;i<=n;i++) sum+=arr[i]*ans[i];
        if(sum) for(int i=sum>0?idxN:idxP;i<=n;i++) ans[i]+=abs(sum);
        for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}
```