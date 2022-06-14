def read():
    return int(input())

def reads():
    return str(input())

def readline():
    return list(map(int,input().split()))

class fenwick:
    def __init__(self,n) -> None:
        self.n=n
        self.tr=[0]*(n+1)

    def lowbit(slef,x) -> int:
        return x&(-x)

    def add(self,pos) -> None:
        while(pos<=self.n):
            self.tr[pos]+=1
            pos+=self.lowbit(pos)

    def query(self,pos) -> int:
        res=0
        while(pos):
            res+=self.tr[pos]
            pos-=self.lowbit(pos)
        return res

def solve():
    n=read()
    arr=[0]+readline()
    cnt=[0]*(n+1)
    ans=0
    tr=fenwick(n)
    for i in range(n,0,-1):
        ans+=tr.query(arr[i])
        tr.add(arr[i])
    print(ans)

if __name__ == "__main__":
    T=read()
    for i in range(T):
        solve()