def read():
    return int(input())

def solve():
    t=read()
    print("Division",end=" ")
    if t>=1900:
        print(1)
    elif t>=1600:
        print(2)
    elif t>=1400:
        print(3)
    else:
        print(4)

if __name__ == "__main__":
    T=read()
    for i in range(T):
        solve()