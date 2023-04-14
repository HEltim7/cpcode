#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
int cnt[1<<7];

void solve() {
    string s;
    cin>>s;
    for(int i='a';i<='z';i++) cnt[i]=0;
    for(auto x:s) cnt[x]++;
    int maxx='a';
    for(int i='a';i<='z';i++) if(cnt[i]) maxx=max(maxx,i);

    string pre,suf;
    string sig;
    for(int i='a';i<='z';i++) {
        int t=cnt[i];
        for(int j=1;j<=t/2;j++) pre.push_back(i),suf.push_back(i);
        if(t&1) {
            int c=0;
            for(int j=i+1;j<='z';j++) if(cnt[j]) c++;
            if(c==0) sig.push_back(i);
            else if(c==1) {
                sig.push_back(i);
                for(int j=1;j<=cnt[maxx];j++) {
                    if(j&1) pre.push_back(maxx);
                    else suf.push_back(maxx);
                }
            }
            else {
                sig.push_back(i);
                for(int j=i+1;j<='z';j++) {
                    for(int k=1;k<=cnt[j];k++) {
                        pre.push_back(j);
                    }
                }
            }
            break;
        }

    }

    reverse(suf.begin(),suf.end());
    string ans=pre+sig+suf;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}