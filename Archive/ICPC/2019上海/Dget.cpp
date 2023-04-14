#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cout<<i<<endl;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            cout<<i<<' '<<j<<endl;
    return 0;
}
/*
1
2
3
4
5
6
1 2
1 3
1 4
1 5
1 6
2 3
2 4
2 5
2 6
3 4
3 5
3 6
4 5
4 6
5 6
*/