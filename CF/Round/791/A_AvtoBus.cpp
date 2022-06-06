#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    LL cnt;
    cin>>cnt;
    LL res;
    res=cnt/12*2;
    int t=cnt%12;
    if(t==0) cout<<res<<' ';
    else if(t==2){
        if(res) cout<<res+1<<' ';
        else {
            cout<<-1<<endl;
            return;
        }
    }
    else if(t==4||t==6) cout<<res+1<<' ';
    else if(t==8||t==10) cout<<res+2<<' ';
    else {
        cout<<-1<<endl;
        return ;
    }

    res=cnt/12*3;
    if(t==0) cout<<res<<endl;
    else if(t==2) cout<<res<<endl;
    else if(t==4||t==6) cout<<res+1<<endl;
    else if(t==8||t==10) cout<<res+2<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}