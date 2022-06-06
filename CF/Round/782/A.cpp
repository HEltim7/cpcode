#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,r,b;
        cin>>n>>r>>b;
        int len=(r+b)/(b+1);
        int part=(r+len-1)/len;
        int out=max(0,b-part);
        for(int cnt=len;r||b;){
            if(cnt&&r) cout<<'R',cnt--,r--;
            else {
                cout<<'B';
                cnt=len;
                b--;
                if(out) cout<<'B',out--,b--;
            }
        }
        cout<<endl;
    }
    return 0;
}