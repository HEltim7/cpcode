def read():
    return int(input())

def readline():
    return list(map(int,input().split()))

def solve():
    s=str(input())
    if(ord(s[0])+ord(s[1])+ord(s[2])==ord(s[3])+ord(s[4])+ord(s[5])):
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    T=read()
    for i in range(T):
        solve()