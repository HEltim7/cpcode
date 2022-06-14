import sys
def read():
    return int(input())

def reads():
    return str(input())

def readline():
    return list(map(int,input().split()))

N=int(4000+10)
adj=[]
ans=0
s=""

def dfs(u):
    res=0
    global ans
    global s
    if s[u]=='B': res=1
    else: res=-1
    for v in adj[u]:
        res+=dfs(v)
    if res==0: ans+=1
    return res

def solve():
    global s
    global ans
    global adj
    n=read()
    arr=readline()
    s=reads()
    ans=0
    adj=[[] for i in range(n)]
    for i in range(n-1):
        adj[arr[i]-1].append(i+1)
    dfs(0)
    print(ans)

if __name__ == "__main__":
    sys.setrecursionlimit(N)
    T=read()
    for i in range(T):
        solve()