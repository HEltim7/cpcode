#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int r1=-1,r2,c1,c2;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char in;
            cin>>in;
            if(in=='o') {
                if(r1==-1) r1=i,c1=j;
                else r2=i,c2=j;
            }
        }
    cout<<abs(r1-r2)+abs(c1-c2);
}