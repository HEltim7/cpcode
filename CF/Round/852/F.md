首先将询问离线，按照右端点排序。

$dp[i]$表示右侧元素中与$a[i]$的最小差异值。从左往右扫，假设当前已经计算完$r$,考虑如何更新到$r+1$

对于$j<i$，分两部分考虑，$a[j]>a[i]$和$a[j]<a[i]$，不妨先考虑$a[j]>a[i]$

如果存在$l<j<i$且$a[l]>a[j]>a[i]$，那么$dp[l]$必然不会被更新，因为$|a[l]-a[j]|<|a[l]-a[i]|$。

所以$dp[l]$会被$a[i]$更新的情况就是$|a[l]-a[j]| > |a[l]-a[i]|$

- 若$a[l]>a[i]$
  - $\Rightarrow a[j]-a[l]>a[l]-a[i] \Rightarrow a[l]<\frac{a[j]+a[i]}{2}$
- 若$a[l]<a[i]$
  - $\Rightarrow a[l]<a[i]$

即存在这样的$a[j]$时只有$a[l] \in [0,\frac{a[j]+a[i]}{2})$的$dp$值才会被更新。

类似地，若有$a[k]<a[i]$，可以得到$a[l] \in (\frac{a[k]+a[i]}{2},n]$