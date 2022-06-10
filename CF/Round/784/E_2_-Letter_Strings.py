def read():
    return int(input())

def readline():
    return list(map(int,input().split()))

def solve():
    n=read()
    matrix=[[0]*30 for i in range(30)]
    for i in range(n):
        s=str(input())
        a=ord(s[0])-ord('a')
        b=ord(s[1])-ord('a')
        matrix[a][b]+=1
    # for i in matrix: print(i)
    ans=0
    for i in range(26):
        pre=0
        for j in range(1,26):
            pre+=matrix[i][j-1]
            if matrix[i][j]:
                ans+=matrix[i][j]*pre
    for i in range(26):
        pre=0
        for j in range(1,26):
            pre+=matrix[j-1][i]
            if matrix[j][i]:
                ans+=matrix[j][i]*pre
    print(ans)

if __name__ == "__main__":
    T=read()
    for i in range(T):
        solve()