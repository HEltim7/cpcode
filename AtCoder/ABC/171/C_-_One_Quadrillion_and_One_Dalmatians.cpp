#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;

void solve() {
    LL n;
    cin>>n;
    if(n<=26) {
        cout<<char('a'+n-1)<<endl;
        return;
    }
    string ans;
    
    int len;
    vector<LL> num(1,1),pre(1,0);
    for(len=0;;len++) {
        if(pre.back()>=n) {
            pre.pop_back();
            num.pop_back();
            debug(num,pre);

            for(int j=1;j<=26;j++) {
                if(pre.back()+1+j*num.back()-1>=n) {
                    ans.push_back(j+'a'-1);
                    n-=pre.back()+1+(j-1)*num.back();
                    break;
                }
            }
            break;
        }
        else {
            num.push_back(num.back()*26);
            pre.push_back(num.back()+pre.back());
        }
    }
    if(pre.back()==n) len--;
    debug(len,ans,n);
    len--;

    string res;
    while(n) {
        res.push_back(n%26+'a');
        n/=26;
    }
    while(res.length()<len) res.push_back('a');
    reverse(res.begin(),res.end());
    debug(res);
    ans+=res;
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}