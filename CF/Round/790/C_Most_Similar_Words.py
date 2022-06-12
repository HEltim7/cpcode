def read():
    return int(input())

def readline():
    return list(map(int,input().split()))

def solve():
    tmp=readline()
    n,m=tmp[0],tmp[1]
    ls=["" for i in range(n)]
    for i in range(n):
        ls[i]=str(input())
    ans=1e3
    for i in range(n):
        for j in range(i+1,n):
            res=0
            for k in range(m):
                res+=abs(ord(ls[i][k])-ord(ls[j][k]))
            ans=min(ans,res)
    print(ans)

if __name__ == "__main__":
    T=read()
    for i in range(T):
        solve()