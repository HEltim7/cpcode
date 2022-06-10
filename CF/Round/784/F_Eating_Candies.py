def read():
    return int(input())

def readline():
    return list(map(int,input().split()))

def solve():
    n=read()
    arr=readline()
    ans,cur=0,0
    a,suma=-1,0
    b,sumb=n,0
    while True:
        if a>=b: break
        elif suma>sumb:
            b-=1
            sumb+=arr[b]
            cur+=1
        elif suma<sumb:
            a+=1
            suma+=arr[a]
            cur+=1
        else :
            ans=cur
            a+=1
            b-=1
            suma+=arr[a]
            sumb+=arr[b]
            cur+=2
    print(ans)


if __name__ == "__main__":
    T=read()
    for i in range(T):
        solve()