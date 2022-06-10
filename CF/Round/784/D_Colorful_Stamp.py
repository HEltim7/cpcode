def read():
    return int(input())

def readline():
    return list(map(int,input().split()))

def solve():
    n=read()
    s=str(input())
    red=blue=0
    ans=True
    for c in s:
        if c=='R': 
            red+=1
        elif c=='B': 
            blue+=1
        else: 
            ans&=blue|red==0 or red>=1 and blue>=1
            red=blue=0
    
    if red|blue: ans&=red>=1 and blue>=1
    if ans: print("YES")
    else: print("NO")

if __name__ == "__main__":
    T=read()
    for i in range(T):
        solve()