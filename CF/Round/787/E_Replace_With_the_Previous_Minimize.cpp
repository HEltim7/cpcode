#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    char maxx='a';
    for(auto x:s){
        if(x<=maxx) continue;
        if(x-maxx>k) {
            char cur=x-k;
            for(auto y:s) {
                if(y<=maxx) cout<<'a';
                else if(y>=cur&&y<=x) cout<<cur;
                else cout<<y;
            }
            cout<<endl;
            return;
        }
        else {
            k-=x-maxx;
            maxx=x;
        }

        if(k<=0) break;
    }

    for(auto x:s) 
        if(x<=maxx) cout<<'a';
        else cout<<x;
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