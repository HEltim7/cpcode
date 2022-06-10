def read():
    return int(input())

def readline():
    return list(map(int,input().split()))

def solve():
    tmp=readline()
    n,k=tmp[0],tmp[1]
    arr=readline()
    ans=0
    for j in range(30,-1,-1):
        cnt=0
        for i in range(n):
            if arr[i]&(1<<j)==0:
                cnt+=1
        if cnt<=k:
            k-=cnt
            ans+=1<<j
    print(ans)

if __name__ == "__main__":
    T=read()
    for i in range(T):
        solve()