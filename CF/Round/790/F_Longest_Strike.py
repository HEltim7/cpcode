def read():
    return int(input())

def reads():
    return str(input())

def readline():
    return list(map(int,input().split()))

def solve():
    dic={}
    n,k=readline()
    arr=readline()
    arr.sort()
    cnt=0
    num=[(0,0)]*(2*n)
    for idx,i in enumerate(arr):
        if(idx>=0 and i-arr[idx-1]>1): cnt+=1
        if i not in dic:
            dic[i]=cnt
            cnt+=1
        (a,b)=num[dic[i]]
        num[dic[i]]=(a+1,i)

    l,L,R=0,-1,-1
    ans=0
    for r in range(cnt):
        if num[r][0]>=k:
            if r-l+1>ans:
                ans=r-l+1
                L,R=num[l][1],num[r][1]
        else: l=r+1
    if(ans!=0): print(L,R)
    else: print(-1)

if __name__ == "__main__":
    T=read()
    for i in range(T):
        solve()