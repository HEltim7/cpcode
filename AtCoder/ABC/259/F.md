# ABC 259 F - Select Edges

## 题意

> [原题连接](https://atcoder.jp/contests/abc259/tasks/abc259_f)

给定一颗有 $N$ 个节点带边权的树，求在树中选择一些边，在满足树中的每个点 $u$ 至多与 $d_u$ 个选择的边相邻的情况下，最大的权值和。

## 思路

这是一道有限制的最优化问题，题目给的是一颗树，我们可以考虑用树形dp来解决。

自下而上来考虑每个树中的节点，我们可以发现一个性质：如果某个点 $u$ 以及选择了 $d_u$ 条与子节点之间的边，那么对于它的父节点 $p$ 来说，$p$ 就不可能再选择 $p \leftrightarrow u$ 这条边，反之，如果 $u$ 与子节点之间只选择了不超过 $d_u-1$ 条边，那 $p$ 就可以选择这条边。

定义：

- $dp[0][i]$ 表示以 $i$ 为根的子树， $i$ 点与子节点之间选择了不超过 $d_u-1$ 条边的最大合法权值和
- $dp[1][i]$ 表示以 $i$ 为根的子树， $i$ 点与子节点之间选择了不超过 $d_u$ 条边的最大合法权值和

很明显，$dp[1][i] \geq dp[0][i]$。对于某个父节点 $p$ 和它的一个子节点 $u$ 来说，我们设他们之间的边的边权为 $w$，如果 $dp[0][u]+w > dp[1][u]$，那么选择这条边是“有收益”的，否则我们一定不会选这条边，因为权值和不会增加，还浪费了 $p$ 选择的次数。

我们现在考虑如何利用上面的性质来更新一个点的状态。设 $p$ 的子节点的集合为 $S$，把上述的收益 $dp[0][u]+w-dp[1][u]$ 记为 $v_u$。把 $S$ 的收益按降序排序，贪心地选择最大的收益，得到状态转移方程：

- $dp[0][p]=\sum_{i=1}^{i\leq d-1}v_i+\sum_{u\in S}dp[1][u]$
- $dp[1][p]=\sum_{i=1}^{i\leq d}v_i+\sum_{u\in S}dp[1][u]$

总共有 $N$ 个节点，每个点最多被父节点计算一次，时间复杂度为 $\mathcal{O(n)}$，另外每一个节点需要将子节点的收益排序，因此总的时间复杂度为 $\mathcal{O(n\log n)}$。

## 实现

记得特判 $d_u=0$ 的情况

```cpp
void dfs(int u,int fa) {
    vector<LL> cur(1,0); //用来保存当前p的收益
    for(auto [v,w]:adj[u]) {
        if(v==fa) continue;
        dfs(v,u);
        dp[0][u]+=dp[1][v]; //加上d情况的权值和
        dp[1][u]+=dp[1][v];
        if(dp[0][v]+w>dp[1][v]) //计算子节点的收益
            cur.push_back(dp[0][v]+w-dp[1][v]);
    }
    sort(next(cur.begin()),cur.end(),greater<LL>());
    int n=cur.size()-1;
    for(int i=1;i<=n;i++) cur[i]+=cur[i-1]; //排序后计算前缀和
    if(d[u]==0) dp[0][u]=-INF;
    else {
        dp[0][u]+=cur[min(n,d[u]-1)]; //贪心拿最大的收益
        dp[1][u]+=cur[min(n,d[u])];
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>d[i];
    for(int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    dfs(1,-1);
    cout<<dp[1][1];
}

```