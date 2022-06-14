def read():
    return int(input())

def reads():
    return str(input())

def readline():
    return list(map(int,input().split()))

def lower_bound(arr,l,r,val):
    while(l<r):
        mid=l+r>>1
        if(arr[mid]>=val): r=mid
        else: l=mid+1
    return l

def solve():
    n,m=readline()
    arr=readline()
    arr.sort(reverse=True)
    pre=[0]*(n+1)
    for i,v in enumerate(arr):
        if i>0: pre[i]=v+pre[i-1]
        else: pre[i]=v
    pre[n]=int(1e15)
    for i in range(m):
        q=read()
        res=lower_bound(pre,0,n,q)
        if(res==n): print(-1)
        else: print(res+1)

if __name__ == "__main__":
    T=read()
    for i in range(T):
        solve()