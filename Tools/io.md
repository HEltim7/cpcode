```cpp
namespace IO {
    const int MAXSIZE = 1 << 20;
    char buf[MAXSIZE], *p1, *p2;
#define gc() \
    (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) ? EOF : *p1++)
}
```

namespace 里面的变量初始值为空，所以两个指针p1,p2=nullptr

最前面的```p1==p2```，这句话是判断两个指针是否指向了同一位置，而p1和p2的具体意思得看后面&&的半句

```cpp
fread(buf, 1, MAXSIZE, stdin)
```
fread从stdin向buf数组一次性写入MAXSIZE个大小为1byte的数据，并返回成功写入的个数

```p1=buf```，所以p1就是指向数组开始的指针

```cpp
p2=(p1=buf)+fread()
```
p2是p1右移成功读入的个数，所以就是数组结尾的后一个，p1,p2结合起来就是数组头尾

```cpp
(p2=...,p1==p2) 
```
括号包起来的多个语句，返回值等于最后一句的返回值，所以它返回的是p1是否到缓存数组buf的末尾

```cpp
p1==p2&&(p2=...,p1==p2)?EOF:*p1++
```
由于三位运算符的优先级比逻辑与运算符低，所以这句话和起来的意思就是：

- 如果第一次执行该语句，此时p1和p2都是nullptr，将数据写入到缓存数组buf，同时返回*p1++，也就是第一个字符
- 反之，p1==p2为false，&&后面的语句直接不执行，继续返回*p1++，即后一个字符
- 当p1再一次等于了p2，说明已经到了缓存数组的结尾，返回EOF

综上：
```cpp
gc()=getchar();
```