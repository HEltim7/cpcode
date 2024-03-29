# A.Creep

## 题意

定义一个01串的分数为这个串0和1个数差值的绝对值，现在给定 $a$ 个 $0$ 和 $b$ 个 $1$，要求构造一个01串，使得它所有前缀的分数最大值最小。

## 思路

首先我们可以发现这个01串不管怎么构造，一定有一个前缀恰好有 $a$ 个 $0$ 与 $b$ 个 $1$ （也就是整个串），所以分数一定 $\geq |a-b|$（同理分数也一定 $\geq 1$），所以我们很自然的就可以想到01交互的构造这个串，然后把最后多出的0/1直接丢最后，这样每个前缀的分数一定不会更大。

时间复杂度 $\mathcal{O(n)}$
## 实现

```cpp
void solve() {
    int a,b;
    cin>>a>>b;
    while(a||b) {
        if(a) cout<<0,a--;
        if(b) cout<<1,b--;
    }
    cout<<endl;
}
```

# B.Paranoid String

## 题意

对于一个01串 $T$，你可以对它进行如下两种操作：

- 将 $T$ 中一个为01的子串替换为1
- 将 $T$ 中一个为10的子串替换为0

当我们能通过若干上述操作把 $T$ 的长度变为1，则我们称 $T$ 合法。

现在给定一个01串 $S$，统计 $S$ 合法的子串个数。

## 思路

观察这两种操作，实际上它等价于一种操作：将两个相邻的不同数的左数删去。

考虑一个串 $T$，若它的最后两个数相同，根据上述的操作，我们无论如何都无法删除最后的两个数，所以此时一定非法。反之如果一个串最后两数不同，我们存在一种方法一定能把串变成只剩最后的两个数，例如: 

$$?????01$$

如果最后的 $0$ 前面有若干 $1$，我们可以直接删去这些1：

$$??1111101 \rightarrow ??01$$

反之如果最后的 $1$ 前面有若干 $0$，我们可以用最后的 $1$ 删去这些 $0$，并留下一个 $0$ 不删：

$$??0000001 \rightarrow ??01$$

重复上述操作，我们就可以把 $T$ 转化成 $01$ 或者 $10$，显然 $01$ 与 $10$ 一定合法。

所以我们得出结论：一个串 $T$ 合法，当且仅当 $T$ 的长度为 $1$ 或者 $T$ 的最后两个数不同。

时间复杂度 $\mathcal{O(n)}$

## 实现

```cpp
void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        char in;
        cin>>in;
        arr[i]=in=='1';
    }
    LL ans=n;
    for(int i=1;i<n;i++) {
        if(arr[i]!=arr[i+1]) {
            ans+=i;
        }
    }
    cout<<ans<<endl;
}
```

# C.Directional Increase

## 题意
我们有一个长度为 $n$ 的数组，初始值全为 $0$，同时有个指针指向第一个位置。

给定一个数组 $a$，问能否通过下面两种操作使得数组变成 $a$

- 指针指向位置的值 $+1$，指针向后移动一位，此时指针不能是最后一位。
- 指向指向位置的值 $-1$，指针向前移动一位，此时指针不能是最前一位。

同时最后指针需要指向第一个位置。

## 思路

因为指针最后需要回到开头，所以数组的权值和总和是不变的，如果 $a$ 的总和不为 $0$，那么一定是```NO```。我们观察一下这两种操作，如果指针从 $x$ 位置移动到 $y$ 再移动回来，那么 $x$ 位置的值会 $+1$，y的位置会 $-1$，而中间的则保持不变，所以指针每在 $x$ 和 $y$ 之间转一圈，$y$ 就会“转移” $1$ 到 $x$ 上。

看出这点之后这题就好办了，从后往前遍历数组 $a$，维护一个值 $sum$，表示后面还有多少值需要转移到前面，当 $sum<0$ 时，则一定非法，反之若遍历结束则为```YES```。

另外有一定需要注意，$x$ 到 $y$ 的一次操作，必须要指针从开头遍历到过 $y$ 才可以，否则操作是非法的，具体可以参考第4个样例。

时间复杂度 $\mathcal{O(n)}$

## 实现

```cpp
void solve() {
    int n;
    cin>>n;
    LL sum=0;
    for(int i=1;i<=n;i++) cin>>arr[i],sum+=arr[i];
    if(sum) {
        cout<<"No"<<endl;
        return;
    }
    for(int i=n;i>=1;i--) {
        if(arr[i]) {
            if(arr[i]>0) {
                cout<<"No"<<endl;
                return;
            }
            else {
                arr[1]--;
                arr[i]++;
            }
            break;
        }
    }
    for(int i=n;i>=1;i--) {
        sum-=arr[i];
        if(sum<0) {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}
```

# D.Fake Plastic Trees

## 题意

我们有一颗根为1的树，每个节点 $v$ 都有一个取值范围 $[l_v,r_v]$，现在我们可以做下面的操作 ~~（建议CodeForces改名OperationForces）~~：

- 选择一条从根到点 $v$ 的路径，然后路径上的每个点按照从根开始的顺序，加上一个值，这些值需要构成一个不递减的序列。

求使得每个点都达到取值范围的最小操作次数。

## 思路

我们可以发现，叶子节点是一定需要赋值的，而且只需要赋一次就可以满足，这启发我们自底向上贪心：从上向下不递减，即从下向上不递增，对于叶子节点，我们直接令它的值为 $r_v$，这样一定不会使结果更差，因为它的父节点可选择的取值范围最大。

我们对于每个点，维护一个值 $val$ 表示子节点对它的贡献（表示父节点再不增加额外操作的前提下最大的可以取到的值），我们可以发现，子节点对父节点的贡献是可加的，所以贡献即为子节点的取值之和。如果 $val$ 不能满足一个点的 $l_v$ 那么我们同样贪心地将其赋值为 $r_v$，然后将答案 $+1$。

按照拓扑序遍历即可，注意节点的取值不能超过 $r_v$。

时间复杂度 $\mathcal{O(n)}$

## 实现

```cpp
void solve() {
    int n;
    cin>>n;
    queue<int> q;
    memset(val,0,sizeof (LL)*(n+1));
    for(int i=2;i<=n;i++) cin>>p[i],ind[p[i]]++;
    for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
    for(int i=1;i<=n;i++) if(!ind[i]) q.push(i);
    LL ans=0;
    while(q.size()) {
        int u=q.front();
        q.pop();
        LL tmp=0;
        if(val[u]>=l[u]) tmp=min(val[u],r[u]);
        else ans++,tmp=r[u];
        if(u!=1) {
            val[p[u]]+=tmp;
            if(--ind[p[u]]==0) q.push(p[u]);
        }
    }
    cout<<ans<<endl;
}
```