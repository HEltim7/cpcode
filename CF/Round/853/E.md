# E. Serval and Music Game

给定长度为$n$的数组，$s_1 < s_2 < \ldots < s_n$

定义$f(x)$为,存在满足下式的$p_i,q_i$的$i$的个数

$$
s_i=p_i\left\lfloor{s_n\over x}\right\rfloor + q_i\left\lceil{s_n\over x}\right\rceil
$$

求$\sum_{x=1}^{s_n} x\cdot f(x)$

$n \le 10^6,s_n \le 10^7$

---

按照 $\left\lfloor{s_n\over x}\right\rfloor$ 和 $\left\lceil{s_n\over x}\right\rceil$ 的关系分类讨论。

### 当 $\left\lfloor{s_n\over x}\right\rfloor = \left\lceil{s_n\over x}\right\rceil$

令 $p_i+q_i=X,\left\lfloor{s_n\over x}\right\rfloor=a$，那么式子就变为了$s_i=Xa$是否存在解。

考虑枚举$a$，那么对于已知的$a$，问题就变成了统计满足$a|s_i$的$i$个数。

如果直接枚举$s_i$会是一个近似调和级数的复杂度，但是我们有更优秀的做法，因为$\left\lfloor{s_n\over x}\right\rfloor = \left\lceil{s_n\over x}\right\rceil$，所以必然有$x|s_n$，也就可以推出$a|s_n$，而又因为我们现在要统计的是$a|s_i$，所以此时$s_i$与$s_n$之间的关系为：$a|\gcd(s_i,s_n)$。

于是我们就可以预处理$\gcd(s_i,s_n)$，和一个$cnt$数组，$cnt[x]$表示$\gcd(s_i,s_n)=x$的$s_i$个数，然后使用数论分块枚举$a$，复杂度为$O(\sqrt s_n)$，然后对于每个$a$枚举$s_n$的的因子$d$，贡献为$cnt[d]$，复杂度也为$O(\sqrt s_n)$。

因此这种情况的时间复杂度就是$O(n\log s_n + \sqrt s_n \sqrt s_n)=O(n\log s_n + s_n)$。

---

### 当 $\left\lfloor{s_n\over x}\right\rfloor +1 = \left\lceil{s_n\over x}\right\rceil$

令 $X=p_i+q_i,Y=q_i,\left\lfloor{s_n\over x}\right\rfloor=a$

那么式子就变为了$s_i=p_ia+q_i(a+1)=(p_i+q_i)a+q_i$即$s_i=Xa+Y$是否存在解，并且$X \ge Y \ge 0$。

如法炮制，我们首先枚举$a$，那么合法的$X$必然满足$X \le \lfloor \frac{s_i}{a} \rfloor \le \lfloor \frac{s_n}{a} \rfloor$。

观察式子$Xa+Y=s_i$，$Y$可取的值为$[0,X]$，那么当$s_i \ge a^2$，即$X \ge a-1$时，总是有解，因为$s_i$除$a$的余数总是可以被$Y$取到。

那么对于每个$a$，我们只需要枚举$X$到$\min \{\lfloor \frac{s_n}{a} \rfloor,a-1\}$即可，预处理值域上$s_i$数量的前缀和来加速这部分的统计。

这部分的时间复杂度为$O(\sqrt s_n \sqrt s_n)=O(s_n)$。

---

总时间复杂度为$O(n\log s_n +s_n)$，如果使用预处理$\gcd$的技巧，可以优化到$O(n+s_n)$。