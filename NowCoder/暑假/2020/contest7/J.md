有26个对象，每个对象里面有26个指针。另有26个全局指针。

- 分配 [指针]=[对象]
  - A=x 指针A能指向x（x能通过A访问
  - add_edge(A,obj)
  - O(1) 且仅执行一次
- 赋值 [指针]=[指针] 
  - A=B 指针能指向所有B指向的对象 
  - add_edge(A,for obj in B) 
  - O(1) 可能执行多次
- 存储 [指针].[字段]=[指针] 
  - A.f=B 对于所有A指向的对象x，x.f能指向所有B指向的对象 
  - add_edge(for obj.f in A,for obj in B) 
  - O(26) 可能执行多次
- 载入 [指针]=[指针].[字段] 
  - A=B.f A能够指向 B指向的所有对象的f指针所 指向的对象
  - add_edge(A,for obj in (for obj.f in B))
  - O(26) 可能执行多次