def read():
    return int(input())

def reads():
    return str(input())

def readline():
    return list(map(int,input().split()))

def solve():
    n,m=readline()
    grid=[[0]*m for i in range(n)]
    for i in range(n):
        grid[i]=readline()

    ans=0
    mvr=[1,1,-1,-1]
    mvc=[1,-1,1,-1]
    for i in range(n):
        for j in range(m):
            res=grid[i][j]
            r,c=i,j
            for k in range(4):
                r,c=i+mvr[k],j+mvc[k]
                while(r<n and r>=0 and c<m and c>=0):
                    res+=grid[r][c]
                    r+=mvr[k]
                    c+=mvc[k]
            ans=max(ans,res)
    print(ans)
            

if __name__ == "__main__":
    T=read()
    for i in range(T):
        solve()