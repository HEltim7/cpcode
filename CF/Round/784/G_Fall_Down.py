def read():
    return int(input())

def readline():
    return list(map(int,input().split()))

def solve():
    nm=readline()
    n,m=nm[0],nm[1]
    grid=["" for i in range(n)]
    for i in range(n):
        grid[i]=str(input())
    for j in range(m):
        cnt=0
        for i in range(n):
            if grid[i][j]=='*':
                cnt+=1
                grid[i]=grid[i][:j]+'.'+grid[i][j+1:]
            if grid[i][j]=='o':
                for k in range(1,cnt+1):
                    grid[i-k]=grid[i-k][:j]+'*'+grid[i-k][j+1:]
                cnt=0
            elif i==n-1:
                for k in range(cnt):
                    grid[i-k]=grid[i-k][:j]+'*'+grid[i-k][j+1:]
                cnt=0

    for i in range(n):
        print(grid[i])
    print()

if __name__ == "__main__":
    T=read()
    for i in range(T):
        solve()