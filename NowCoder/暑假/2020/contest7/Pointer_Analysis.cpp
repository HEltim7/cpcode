#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int A=26,P=A+26*26;
int to[P];

void solve() {
    int n;
    cin>>n;
    string s;
    getline(cin,s);
    vector<tuple<int,int,int,int>> ins;
    for(int i=1;i<=n;i++) {
        getline(cin,s);
        if(find(s.begin(),s.end(),'.')==s.end()) {
            int p=s.front()-'A';
            if(islower(s.back())) {
                int x=s.back()-'a';
                to[p]|=1<<x;
            }
            else ins.emplace_back(1,p,s.back()-'A',0);
        }
        else {
            int dot=find(s.begin(),s.end(),'.')-s.begin();
            int equ=find(s.begin(),s.end(),'=')-s.begin();
            if(dot<equ) {
                int p=s.front()-'A';
                int f=s[dot+1]-'a';
                int q=s.back()-'A';
                ins.emplace_back(2,p,f,q);
            }
            else {
                int p=s.front()-'A';
                int q=s[equ+2]-'A';
                int f=s.back()-'a';
                ins.emplace_back(3,p,q,f);
            }
        }
    }

    bool isok=true;
    while(isok) {
        isok=false;
        for(auto &t:ins) {
            if(get<0>(t)==1) {
                auto [_,p,q,__]=t;
                int old=to[p];
                to[p]|=to[q];
                isok|=old!=to[p];
            }
            else if(get<0>(t)==2) {
                auto [_,p,f,q]=t;
                for(int i=0;i<A;i++) {
                    if(to[p]>>i&1) {
                        int x=(i+1)*A+f;
                        int old=to[x];
                        to[x]|=to[q];
                        isok|=old!=to[x];
                    }
                }
            }
            else if(get<0>(t)==3) {
                auto [_,p,q,f]=t;
                int obj=0;
                for(int i=0;i<A;i++) {
                    if(to[q]>>i&1) {
                        obj|=to[(i+1)*A+f];
                    }
                }
                int old=to[p];
                to[p]|=obj;
                isok|=old!=to[p];
            }
        }
    }

    for(int i=0;i<A;i++) {
        cout<<char('A'+i)<<": ";
        for(int j=0;j<A;j++) if(to[i]>>j&1) cout<<char('a'+j);
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}