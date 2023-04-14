import math

def read():
    return int(input())

def reads():
    return str(input())

def readline():
    return list(map(int,input().split()))

def solve():
    n=read()
    m=(-1+int(math.sqrt(1+4*(2+2*n))))//2
    print("m=",m)
    m1=m-1
    pre=m1*(m1+1)*(2*m1+1)//6+(1+m1)*m1//2
    suf=+(n-(2+m)*(m-1)//2)*m
    print("pre=",pre)
    print("suf=",suf)
    ans=pre+suf
    print(ans)

if __name__ == "__main__":
    T=read()
    for i in range(T):
        solve()