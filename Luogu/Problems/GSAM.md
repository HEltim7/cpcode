# 广义后缀自动机

## 符号

| 符号 | 含义 |
| :-: | :-: |
| $\epsilon,A,A^*,A^+$ | 空字符，字符集，字符集闭包，字符集正闭包 |
| $T,T_x,T_{x,y}$ | Trie树，Trie树上的x节点，Trie树上从x到y构成的字符串 |
| $P_{T_x},P(T)$ | 从根到x的前缀，Trie树的所有前缀 |
| $F(T)$ | Trie树的所有子串 |
| $S(T)$ | Trie树的所有后缀 |
| $Right(x)$ | 字符串x的出现位置集合（下面记作endpos） |
| $xRy,R(x)$ | x与y的endpos相同，与x endpos相同的字符串集合 |
| $\Phi(T),\Phi(T)_x$ | 后缀自动机，后缀自动机的x状态 |
| $s(x)$ | x的后缀连接（指向的字符串） |

## 引理4.1

令 $x,y\in F(T)$，有：

1. $\forall y,\text{not }xRs(y) \Rightarrow |endpos(x)|=1$
2. $|endpos(x)|=1 \Rightarrow P_{T_x}Rx (endpos(x)=\{T_x\})$
3. $\forall T_v \in Right(x), \text{not } xRP_{T_v} \Rightarrow \exist u, v, s(u)Rs(v)Rx \text{ and not } uRv$

$\Longleftrightarrow$

**1. 如果没有任何的字符串的后缀连接endpos和x相等，那么x的endpos集合大小为1。**

对位证明法，考虑逆否命题 $|endpos(x)|\not ={1} \Rightarrow \exist y,xRs(y)$，因为必定存在一个 $y$ 满足 $s(y)=x$ ，而 $xRx$ ，所以原命题得证。

**2. 字符串$x$的$endpos$大小为1，不妨设$endpos(x)=\{T_z\}$，则从$Trie$根到$T_z$对应的字符串的$endpos$和$x$相同。**

这个很容易证明，即$endpos$相同的后缀是连续的一段。

**3. 如果对于任意的$endpos(x)$中的位置$T_v$，都有$endpos(x)$和$endpos(P_{T_v})$不同，则必定存在两个$endpos$不同的字符串满足$s(u)Rs(v)Rx$**

根据引理4.1.2的逆否命题，我们知道$|endpos(x)|\geq 2$。$SAM$的性质。

---

## 定理：状态数为线性

根据引理4.1.3的逆否命题，如果$Parent$树上某个点只有一个子节点/没有子节点，那么它一定对应某个$Trie$的前缀，而且这些点对应的前缀两两之间互不相同（否则endpos会相同）。那么因为$Trie$只有$|T|$个节点，所以这些点的数量也是$|T|$。所以有两个以上子节点的节点数量一定小于$|T|$，所以总共的节点数量小于$2|T|$。

## 定理：转移数上界为$O(|T||\Sigma|)$

每个点最多有$O(|\Sigma|)$条转移边。链套菊花的$Trie$即可到达这个上界。

# 构造算法

复杂度下界为状态数和转移数之和，$O(|T||\Sigma|)$。

在$Trie$的$T_x$节点后加入$T_y$，字符$a$，得到$TN$，$s=P_{T_x}$。

## 状态变化

下面讨论增加一个字符之后自动机的状态和后缀链接的变化。

### Case1

> 不产生新串并且等价类恰好不变

如果$T_x$已经有$a$这个儿子，那么加完$T_y$我们肯定什么都不用干。考虑新增的字符串是从从根到$T_y$的所有后缀，而这就相当于从根到$T_x$的这些后缀，等价与这些endpos全部加上$T_y$，所以等价类均保持不变。

这个$case$实际上就是一个等价类全部变化的情况，类似$SAM$的这种情况：

```cpp
if(edp[p].len+1==edp[q].len) edp[cur].link=q;
```

### Case2

> 不产生新串，分裂等价类

如果$sa\in F(T)$，即$\Phi(T)_sa=\Phi(T)_{sa}$，那么我们可能需要分裂一个endpos。

我们可以得出几个结论。

**$\forall xR_{TN}sa,yR_{TN}sa$，均有$xR_Ty$。**

证明，根据条件，我们知道$xR_{TN}y$，并且$T_y\in endpos_{TN}(x)$，那么如果我们从$endpos_{TN}$中移除$T_y$，$x,y$的$endpos$依然相等，而此时恰巧就是$T$的情况，所以$xR_Ty$。

考虑什么时候需要分裂：

- 如果满足$\forall x\in R_T(sa),xR_{TN}sa$，那么不需要分裂，此时相当于整个等价类的$endpos$都加上$T_y$。
- 反之如果$\exist x\in R_T(sa),\text{not }xR_{TN}sa$，那么这个等价类中一部分串的$endpos$加上了$T_y$，另一些则保持不变，并且根据性质它们肯定是连续的。

现在我们考虑如何维护分裂后两个状态的后缀链接。为了方便，设两个字符串$u,v$，分别代表$endpos$变和不变的情况，即$u,v\in F(T), uR_{TN} sa,\text{not } vR_{TN} sa$ 且 $uR_Tsa,vR_Tsa$。

那么$s_T(u)=s_{TN}(u)$，因为这些后缀的$endpos$都加上了$T_y$。而对于$v$来说，它的后缀链接就必须改变，实际上$s_{TN}(v)=sa$。

### Case3

> 产生新串，等价类分裂

$sa\notin F(T)$，那我们势必要新建一个等价类$R_{TN}(sa)$。同时也有可能发生等价类分裂。

一个比较显然的结论：$s_{TN}(sa)$ 等于$S(sa)$在$F(T)$中的最长串。

所以我们新建完一个等价类之后，再套用$Case2$解决剩下的部分即可。

## 转移函数变化

然后讨论转移函数的变化。

### Case1

因为自动机状态不变，所以转移函数也不变。

### Case2

如果没有分裂等价类，则不需要修改转移函数。首先对于我们分裂的等价类，它们的转移函数保持不变，$\Phi(TN)_ux=\Phi(TN)_vx=\Phi(T)_{sa}x$。

而转移向它们的状态则需要修改转移函数，类似$SAM$，我们只需要修改长度在$R_{TN}(v)$范围内的等价类即可。具体做法是新建一个节点$clone$代表$u$的部分，不断的跳后缀链接，把转移指向$clone$，直到转移不再指向$R_T(v)$，即$\Phi(T)_{sa}$为止。

### Case3

我们新建了一个状态$\Phi(TN)_{sa}$，因为$T_y$是叶节点，所以$\Phi(TN)_{sa}$的转移函数为空。和$Case2$类似，不断跳后缀链接，直到一个状态已经存在了一个$a$转移。对于剩下的部分，同样套用$Case2$解决即可。