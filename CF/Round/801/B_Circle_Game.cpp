#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    int min1=2e9,min2=2e9;
    int pos1,pos2;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(i&1) {
            if(in<min1) {
                min1=in;
                pos1=i;
            }
        }
        else {
            if(in<min2) {
                min2=in;
                pos2=i;
            }
        }
    }
    if(n&1) cout<<"Mike"<<endl;
    else if(min1<min2) cout<<"Joe"<<endl;
    else if(min2<min1) cout<<"Mike"<<endl;
    else if(pos1<pos2) cout<<"Joe"<<endl;
    else cout<<"Mike"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}