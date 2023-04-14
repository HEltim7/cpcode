# CCPC 2022 网络赛简要题解

水个CCPC网络赛题解，整体来说打的比较烂。小作文在文章尾。

## Problem M. Count Permutation 2

### 题意

给定一个长度为 $n$ 的排列和一个整数 $k$ ，每次操作可以选择一个长度为 $k$ 的区间，使这个区间的数全部变成区间最大值，求最少的操作次数使得整个序列的值都为 $n$。

### 思路

签到题，贪心即可。观察到每次拓展区间最多把 $k-1$ 个值变成 $n$，整个序列一共有 $n-1$ 个值需要变成 $n$ ，所以答案就是 $\lceil \frac{n-1}{k-1} \rceil$。

### 实现

```cpp
void solve() {
    int n,k;
    cin>>n>>k;
    cout<<(n-1+k-2)/(k-1);
}
```

## Problem K. Roulette

### 题意

交互题，赌博游戏。你有 $10^{700}$ 的钱，每次你需要押注 $x$ 的本金，结果有两种：

- 胜，你获得 $2x$
- 负，你什么都不会得到

你需要赚取 $y$ 的金钱，已知胜利的概率是 $p$，判题程序会告诉你每次的结果，输出每次押注的金额。

#### 数据范围

$y\leq 10^{18},p\in[\frac{1}{100},1]$

### 思路

发现起始金额非常巨大，所以我们可以采取以下的策略，使我们胜利的期望最大：

- 直接押注 $x$，此时结果有两种
    - 成功，我们直接达成了目标
    - 失败，将 $x$ 更新为 $2x$
- 重复上述步骤

根据我们的策略，一旦我们胜利，我们就会直接达成目标，因为我们总是押注目标值，考虑到本金大致能供我们押注 ```2000~3000``` 次左右(准确来说是 $\log_2{10^{700-18}}-1$)，即使考虑最坏的情况，$p=\frac{1}{100}$，我们能达成目标的期望依然非常高。~~(如果实在是太倒霉那多交几发总能过的~~

> 我可以一直输，但我只需要赢一把

### 实现
写个高精度加法即可。

```cpp
using LL=long long;
using VI=vector<int>;

VI get(LL x) {
    VI res;
    while(x) res.push_back(x%10),x/=10;
    reverse(res.begin(),res.end());
    return res;
}

void output(VI &x) {
    for(auto i:x) cout<<i;
    cout<<endl;       
}

VI add(VI x) {
    reverse(x.begin(),x.end());
    VI res;
    int cur=0;
    for(int i=0;i<x.size();i++) {
        cur=cur+x[i]*2;
        res.push_back(cur%10);
        cur/=10;
    }
    if(cur) res.push_back(cur);
    reverse(res.begin(),res.end());
    return res;
}

void solve() {
    LL y,seed;
    int q;
    cin>>y>>q>>seed;
    VI cur=get(y);
    for(;;) {
        output(cur);
        int res;
        cin>>res;
        if(res==2) return;
        if(res==1) assert(0);
        if(res==0) cur=add(cur);
    }
}
```

## Problem A. Doubt VS Lie

读题题，模拟题。感觉这题没什么好讲的，只要读懂题意然后嗯写就行了。~~（刚开始以为是博弈还认真的整理游戏规则的我是笨蛋捏~~

### 实现

```cpp
using LL=long long;
using PII=pair<int,int>;
using MST=multiset<int>;
constexpr int n=13,m=4;

array<MST,4> hand,desk;
array<PII,4> state;

void solve() {
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            int in;
            cin>>in;
            hand[i].insert(in);
        }
    }

    int q,x,y,cur=0;
    cin>>q;
    while(q--) {
        char op;
        cin>>op;
        if(op=='S') {
            cin>>x>>y;
            for(int i=1;i<=y;i++) {
                int in;
                cin>>in;
                desk[cur].insert(in);
                hand[cur].erase(hand[cur].find(in));
            }
            state[cur]={y,x};
        }
        else if(op=='!') {
            cin>>y;
            for(int i=1;i<=y;i++) {
                int in;
                cin>>in;
                desk[cur].insert(in);
                hand[cur].erase(hand[cur].find(in));
            }
            state[cur]={y,x};
        }
        else {
            int last=(cur-1+m)%m;
            int cnt=desk[last].count(state[last].second);

            int loser=cnt==state[last].first?cur:last;
            for(int i=0;i<m;i++) {
                for(auto x:desk[i]) hand[loser].insert(x);
                desk[i].clear();
            }
        }

        cur=(cur+1)%m;
    }

    for(int i=0;i<m;i++) {
        for(auto x:hand[i]) cout<<x<<' ';
        cout<<endl;
    }
}
```

## Problem C. Guess

### 题意

博弈题，猜数字游戏。$Alice$ 和 $Bob$ 又在玩游戏，每个人头上都有一个数字，他们只能看到互相的数字，但是看不到自己的。并且其中一个人的数字一定是另一个人的两倍（均为整数）。$Alice$ 先手，每轮执行以下操作：

- 如果能 $100\%$ 确定自己的数字，自己说出答案，否则就说不知道。
- 当一名玩家猜出数字时，该玩家胜利，游戏结束。

### 思路

先约定一些符号，```A B```分别代表 $Alice$ 和 $Bob$，```x !```分别表示“不知道”和“知道”。

考虑递推地研究这个问题。

#### 场景1

首先考虑最简单的情况：

```
 A=2 | B=1
```
那么此时A发现B是奇数，所以自己一定是2，结束。

决策路径：

| Round | Alice | Bob |
| :---: | :---: | :-: |
|   1   |   !   |     |

#### 场景2

也是最简单的情况：

```
 A=1 | B=2
```
此时A发现B是偶数，那么自己有两种可能 `1,4`，所以A并不知道自己到底是那种，所以会说不知道。B发现A为奇数，所以自己一定是2，结束。

| Round | Alice | Bob |
| :---: | :---: | :-: |
|   1   |   x   |  !  |

#### 场景3

我们不妨设已知答案的场景为终结态，那么我们现在有了两个终结态，现在可以考虑更加复杂的情况。

```
 A=4 | B=2
```
- 第一轮
    - A发现B等于2，当前局面不属于任何已知的终结态，所以会说不知道。
    - B发现A等于4，当前局面也不属于任何终结态，所以也说不知道。

- 第二轮
    - A发现B等于2时却说了不知道，那么根据场景2的答案，若自己为1，B肯定会说知道，所以自己一定不是1，那么自己只有一种可能，那就是4,结束。

| Round | Alice | Bob |
| :---: | :---: | :-: |
|   1   |   x   |  x  |
|   2   |   !   |     |

#### 场景4

```
 A=2 | B=4
```

- 第一轮
    - A发现B是4，当前局面不属于任何终结态，所以会说不知道
    - B发现A等于2时却说了不知道，那么根据场景1的答案，若自己为1，A肯定会说知道，所以自己一定不是1，那么自己只有一种可能，那就是4,结束。

| Round | Alice | Bob |
| :---: | :---: | :-: |
|   1   |   x   |  !  |

#### 场景5

```
 A=8 | B=4
```

- 第一轮
    - A发现B是4，当前局面不属于任何终结态，所以说不知道
    - B发现A是8，当前局面不属于任何终结态，所以说不知道
- 第二轮
    - A发现B等于4时却说了不知道，那么根据场景4的答案，若自己为2，B肯定会说知道，所以自己一定不是2，那么自己只有一种可能，那就是8,结束。

| Round | Alice | Bob |
| :---: | :---: | :-: |
|   1   |   x   |  x  |
|   2   |   !   |     |

#### 总结

你可以思考一下 `A=32,B=16` 的情况，答案是 $Alice$ 在第3轮获胜。

还有一个结论，那就是对于我们上面分析的场景，AB都乘上一个奇数，答案不变，这点很容易推导出。

那么我们就可以发现，实际上答案只和AB中因子2的个数有关，且2多的必胜。

### 实现

```cpp
void solve() {
    LL a,b,cnta=0,cntb=0;
    cin>>a>>b;
    while(a&&a%2==0) a/=2,cnta++;
    while(b&&b%2==0) b/=2,cntb++;
    cout<<(cnta/2+1)<<' '<<(cnta>cntb?0:1)<<endl;
}
```

## 碎碎念&比赛总结

这场我们刚开始还是比较顺利的，前2小时我A出3道题，都是一发过，但很奇怪的是队友讨论了几乎两小时的博弈，WA了好几发都没出。此时我赶紧去支援C(重点讲下这个C，小剧场)。

然后发生了如下对话：

```
队友A：我知道你是偶数那我肯定要猜一个大的
队友B：我知道你也是偶数那我肯定也要猜一个xxx
我：你们赶紧去开别的题，别吊死在一颗树上，一道题做久了思路就僵化了
```

不过还是隔壁队比较厉害：

```
队员X：Bob你是偶数那我肯要猜一个假的干扰你判断
队员Y：你Alice能演我我不能演你？我只要瞎猜一个xxx就有50%的概率猜中，反正我肯定亏不了顺便还能演你一手
```

之后我读完题就觉得不对劲了，题目说道很明白：

> Both of them are smart enough and they won’t make mistakes. They will speak out the answer if and 
> only if they exactly know it, otherwise, they will say "I don’t know"instead.

```
我：题目都写了 **exactly** **I don’t know**，那应该是一直说不知道才对，你们这瞎猜肯定是题目读假了
队友A：我读了好几遍题了，就是这个意思，你再看看上一段说 **try to guess**，不去guess怎么try
队友B：而且怎么可能一直说不知道不知道突然就知道了，这显然违反常理
```

在队友又去WA了几发的同时我认真地研究了一下样例`A=4,B=8`并断言“一定是一直说不知道不知道就知道了”，然后说完这句话的时候全实验室的人都在笑我。

结果是大概在3h的时候一发A出了C。两个队友贡献了8发WA看起来感到愧疚无比。

之后剩下的时间只剩一个小时多，我上去用贪心+SAM莽了一发E，果不其然收获一发WA，分析了一下发现贪心非常假，又考虑是不是什么神秘的SAM上跑dp，发现也比较棘手 ~~（最后正解是纯dp）~~。就让出机位让队友冲H题。

H题队里的数学手提出了一个整除分块的做法，感觉十分靠谱，只可惜最后差了点时间没调出来。（最后正解还要质因数分解优化，所以也不算太可惜）

---

总的来说因为各种阴差阳错我们队的4道题全是我过的 ~~（早知道报单挑）~~，**当然这并没有责备他们的意思**，因为是人总会犯错，没准下次就轮到我背大锅了。

另外我感觉这场的题都还是比较有意思的，居然能在XCPC看到交互题，那个博弈虽然是我们队最大的败笔，但不得不承认这道题出的还是很妙的。

不过相比去年来说，我们总算是拿到了CCPC的名额（$0\rightarrow 1$），对于我们这种弱校，实际上就算是一个名额也足够了（全校没几个队）。

打XCPC一定不要吊死在一颗树上，要知道三个人只有15小时，而仅仅C一道题就耗费了我们队合计7-8小时的时间，相当于少了一个半的队员。

---

最后玩下梗：
![做题不能凭运气.png](https://cdn.acwing.com/media/article/image/2022/09/12/69079_f019edab32-做题不能凭运气.png) 

```
[某场多校]
队友A：我刚才瞎猜连WA了两发，做题一定不能凭运气
**说罢微调代码又猜一发**
**AC音效**
我&队友B：对，做题不能凭运气！
```
~~有时候博弈题就是要凭运气~~