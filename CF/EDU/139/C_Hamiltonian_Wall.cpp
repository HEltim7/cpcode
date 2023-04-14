#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
bool mark[2][N];

void solve() {
    int n;
    string s[2];
    cin>>n;
    cin>>s[0]>>s[1];
    int cnt=0;
    for(int i=0;i<2;i++) for(int j=0;j<n;j++) cnt+=s[i][j]=='B';
    if(cnt==0) {
        cout<<"YES"<<endl;
        return;
    }

    auto work=[&](int x,int y) {
        memset(mark[0],0,sizeof(bool)*n);
        memset(mark[1],0,sizeof(bool)*n);
        bool res=1;
        mark[x][y]=1;
        for(int i=1;i<cnt&&res;i++) {
            if(!mark[x^1][y]&&s[x^1][y]=='B') {
                mark[x^1][y]=1;
                x^=1;
            }
            else if(y+1<n&&s[x][y+1]=='B') {
                mark[x][y+1]=1;
                y++;
            }
            else res=0;
        }
        return res;
    };
    
    int x=-1,y=-1;
    for(int i=0;i<n&&x==-1;i++)
        for(int j=0;j<2&&x==-1;j++)
            if(s[j][i]=='B') x=j,y=i;
    
    bool res=work(x,y);
    if(!res&&s[x^1][y]=='B') res=work(x^1,y);
    cout<<(res?"YES":"NO")<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}