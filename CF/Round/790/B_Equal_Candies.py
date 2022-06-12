def read():
    return int(input())

def readline():
    return list(map(int,input().split()))

def solve():
    n=read()
    arr=readline()
    minn=1e7
    for i in range(n):
        minn=min(minn,arr[i])
    ans=0
    for i in range(n):
        ans+=arr[i]-minn
    print(int(ans))

if __name__ == "__main__":
    T=read()
    for i in range(T):
        solve()