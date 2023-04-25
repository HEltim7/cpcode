# ucup stage 13 Iberia Problem K. 4

~~Um_nik从[2021南京K](https://codeforces.com/gym/103470/problem/K)抄的~~

~~然后两题我都不会QAQ~~

## 题意

[原题链接](https://qoj.ac/contest/1212/problem/6354)

给定一个简单图，$n$ 个点 $m$ 条边，求四元团的数量。

$n,m \le 10^5$。

## 思路

首先是大小度分治的Trick，将所有点按照度数排序，每个点的邻接表 $adj$ 仅保留排在其右侧的点。$adj_i$ 的节点数量为 $d_i$，度数为 $deg_i$。所有点的度数之和为 $2m$。若 $deg_i\le \sqrt{2m}$ 那么显然 $d_i \le \sqrt{2m}$。若 $deg_i > \sqrt{2m}$，由于这些点的数量不会超过 $\sqrt{2m}$ 个，那么其必然在数组的后 $\sqrt{2m}$ 位置，而我们仅向右侧连边，因此 $d_i < \sqrt{2m}$。

按照这种方式处理后，我们保证了 $\forall_i d_i \le \sqrt{2m}$。

由于一个 $x$ 元团 $K_x$ 是由 $x$ 个 $K_{x-1}$ 组成的，因此在求四元团 $K_4$ 之前，我们先考虑求出三元团 $K_3$，然后用 $K_3$ 推出 $K_4$。

对于 $K_3$，我们先暴力枚举一个点 $u$，将 $u$ 作为团中编号最小的顶点，然后遍历 $u$ 的邻接表，不妨设当前遍历到的点为 $v$，那么对于 $\forall w \in adj_u \cap adj_v$，均满足 $(u,v,w)$ 是一个 $K_3$。将邻接表排序后，可以在 $\mathcal{O}(d_u+d_v) = \mathcal{O}(\sqrt{m})$ 的时间内用双指针找到所有的 $w$。那么这一步的复杂度就是 $\mathcal{O}(\sum_i d_i\sqrt{m})=\mathcal{O}(\sqrt{m}\sum_i d_i)=\mathcal{O}(m\sqrt{m})$。

通过暴力的过程不难发现图中 $K_3$ 的数量上界也为 $\mathcal{O}(m\sqrt{m})$，在给定的图是完全图时便可以达到这个上界。

---

现在考虑如何用 $K_3$ 算 $K_4$。定义一个新图 $G_u$，$G_u$ 中的一条边 $(v,w)$ 表示在暴力求三元团时存在 $K_3(u,v,w)$。那么 $G_u$ 中的一个三元团 $K_3(v,w,x)$ 就代表原图中存在 $K_3(u,v,w),K_3(u,v,x),K_3(u,w,x)$，也就是原图存在四元团 $K_4(u,v,w,x)$。

离散化后，使用 `std::bitset` 压位存储一个点能到达的点，枚举 $G_u$ 中的边 $(v,w)$，统计 `(bitset[v]&bitset[w]).count()` 即可在 $\mathcal{O}(\frac{m_ud_u}{w})$ 的时间内解决这个问题，其中 $m_u$ 表示 $G_u$ 的边数，也就是 $K_3$ 的数量。$\mathcal{O}(\sum_u \frac{m_ud_u}{w})=\mathcal{O}(\frac{\sqrt{m}}{w}\sum_u m_u)=\mathcal{O}(\frac{m^2}{w})$。

总的时间复杂度就是 $\mathcal{O}(\frac{m^2}{w})$，空间复杂度 $\mathcal{O}(\frac{m\sqrt{m}}{w})$。

## 实现

[提交记录](https://qoj.ac/contest/1212/problem/6354)

```cpp
constexpr int N=1e5+10,M=450;
vector<int> adj[N];
bitset<M> bs[N];
int deg[N],mp[N];

void solve() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> edg;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        deg[u]++,deg[v]++;
        edg.emplace_back(u,v);
    }
    
    for(auto [u,v]:edg) {
        if(deg[u]<deg[v]+(u<v)) adj[u].push_back(v);
        else adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end());

    LL ans=0;
    for(int u=1;u<=n;u++) {
        edg.clear();
        for(int idx=0; int v:adj[u]) mp[v]=idx++;
        for(int v:adj[u]) {
            bs[v].reset();
            int i=0,j=0;
            while(i<adj[u].size()&&j<adj[v].size()) {
                if(adj[u][i]==adj[v][j]) {
                    edg.emplace_back(v,adj[v][j]);
                    bs[v].set(mp[adj[v][j]]);
                    i++,j++;
                }
                else if(adj[u][i]<adj[v][j]) i++;
                else j++;
            }
        }
        for(auto [v,w]:edg) ans+=(bs[v]&bs[w]).count();
    }

    cout<<ans;
}
```