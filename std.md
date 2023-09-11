# 程序设计题

每道算法设计题，只要作答并且有完整的函数结构，给一半分（向上取整）。

主要目的是凑55分，同时兼顾公平和便于批改。因此只要考生认真作答了每道题，就能获得程序设计保底的23分。

不过多追究程序实现的细节，只要逻辑正确，能体现对应数据结构的思想，不论是基于静态数组模拟的实现还是动态开辟内存的指针实现，都给分。

## 1.栈（20）

### 1-1.初始化栈（5）

```cpp
void InitStack(LinkStNode *&s) {
    s = (LinkStNode *)malloc(sizeof(LinkStNode));
    s->next = NULL;
}
```
- 有尝试作答+2 / 有完整的函数体 +3
- 动态写法
  - 正确申请了内存 +1
  - 有初始化链头 +1
- 静态写法
  - 正确定义静态数组 +1
  - 有初始化栈顶 +1

### 1-2.销毁栈（5）

```cpp
void DestroyStack(LinkStNode *&s) {
    LinkStNode *p = s, *q = s->next;
    while (q != NULL) {
        free(p);
        p = q;
        q = p->next;
    }
    free(p); // 此时p指向尾结点，释放其空间
}
```

- 有尝试作答+2 / 有完整的函数体 +3
- 动态写法：有循环删除链表 +2
- 静态写法：有清空链头 +2

### 1-3.进栈（5）

```cpp
void Push(LinkStNode *&s, ElemType e) {
    LinkStNode *p;
    p = (LinkStNode *)malloc(sizeof(LinkStNode));
    p->data = e;       // 新建元素e对应的结点p
    p->next = s->next; // 插入p结点作为开始结点
    s->next = p;
}
```

- 有尝试作答+2 / 有完整的函数体 +3
- 动态写法：
  - 有新建节点并赋值进栈元素 +1
  - 有正确处理指针变化 +1
- 静态写法：
  - 有特判栈满 +1
  - 有新建节点并赋值进栈元素 +1

### 1-4.出栈（5）

```cpp
bool Pop(LinkStNode *&s, ElemType &e) {
    LinkStNode *p;
    if (s->next == NULL) // 栈空的情况
        return false;
    p = s->next; // p指向开始结点
    e = p->data;
    s->next = p->next; // 删除p结点
    free(p);           // 释放p结点
    return true;
}
```

- 有尝试作答+2 / 有完整的函数体 +3
- 动态写法
  - 有特判栈空 +1
  - 有删除栈顶并正确处理了指针的变化 +1
- 静态写法
  - 有特判栈空 +1
  - 有删除栈顶 +1

## 2.队列（20）

### 2-1.初始化队列（6）

```cpp
SeQueue QueueInit(SeQueue Q) { // 初始化队列
    Q.front = Q.rear = 0;
    Q.tag = 0;
    return Q;
}
```

- 有尝试作答+2 / 有完整的函数体 +3
- 有初始化队头 +1
- 有初始化队尾 +1
- 有初始化标记 +1

### 2-2.入队（7）

```cpp
SeQueue QueueIn(SeQueue Q, int e) { // 入队列
    if ((Q.tag == 1) && (Q.rear == Q.front))
        cout << "队列已满" << endl;
    else {
        Q.rear = (Q.rear + 1) % m;
        Q.data[Q.rear] = e;
        if (Q.tag == 0)
            Q.tag = 1; // 队列已不空
    }
    return Q;
}
```

- 有尝试作答+2 / 有完整的函数体 +4
- 递增队尾并赋值入队元素 +1
- 循环地递增队尾，能体现循环队列思想 +1
- 有特判队满并正确处理标记更新 +1

### 2-3.出队（7）

```cpp
ElemType QueueOut(SeQueue Q) { // 出队列
    if (Q.tag == 0) {
        cout << "队列为空" << endl;
        exit(0);
    } else {
        Q.front = (Q.front + 1) % m;
        e = Q.data[Q.front];
        if (Q.front == Q.rear) // 空队列
            Q.tag = 0;
    }
    return (e);
}
```

- 有尝试作答+2 / 有完整的函数体 +4
- 有递增队头 +1
- 有循环地递增队头，能体现循环队列思想 +1
- 有特判队空并正确处理标记更新 +1