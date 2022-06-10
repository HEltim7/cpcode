def read():
    return int(input())

def readline():
    return list(map(int,input().split()))

def solve():
    n=read()
    arr=readline()
    ans=True
    odd=even=0
    for i in range(0,n,2):
        if arr[i]&1: odd+=1
        else: even+=1
    ans&=odd==0 or even==0
    odd=even=0
    for i in range(1,n,2):
        if arr[i]&1: odd+=1
        else: even+=1
    ans&=odd==0 or even==0
    if ans: print("YES")
    else: print("NO")

if __name__ == "__main__":
    T=read()
    for i in range(T):
        solve()