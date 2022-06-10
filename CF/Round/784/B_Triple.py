def read():
    return int(input())

def readline():
    return list(map(int,input().split()))

def solve():
    n=read()
    dic={}
    ans=-1
    for val in readline():
        if val in dic:
            dic[val]+=1
        else:
            dic[val]=1
        if(dic[val]>=3):
            ans=val
            break
    print(ans)

if __name__ == "__main__":
    T=read()
    for i in range(T):
        solve()