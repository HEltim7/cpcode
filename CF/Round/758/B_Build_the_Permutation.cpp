#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,a,b;
    cin>>n>>a>>b;
    if(abs(a-b)>1||a+b>n-2) {
        cout<<-1<<endl;
        return ;
    }
    int left=n-(a+b+2),dn,up;
    if(a>b) {
        for(dn=left+1,up=n;dn<up;dn++,up--) {
            cout<<dn<<' '<<up<<' ';
        }
        cout<<dn<<' ';
        while(left>0) cout<<(left--)<<' ';
    }
    else if(a==b) {
        for(dn=left+1,up=n;dn<up;dn++,up--) cout<<up<<' '<<dn<<' ';
        while(left>0) cout<<(left--)<<' ';
    }
    else {
        left=a+b+2+1;
        for(dn=1,up=left-1;dn<up;dn++,up--) cout<<up<<' '<<dn<<' ';
        cout<<up<<' ';
        while(left<=n) cout<<(left++)<<' ';
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}