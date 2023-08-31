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
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    string s;
    cin>>s;

    int tot=0;
    int bad_cnt=0,good_cnt=0;
    vector<pair<int,int>> seg;
    // 0=good,1=unkonwn,2=bad
    for(auto x:s) {
        if(x=='+') {
            tot++;
            if(seg.size()&&seg.back().first==1) seg.back().second++;
            else seg.emplace_back(1,1);
        }
        else if(x=='-') {
            tot--;
            if(seg.size()&&seg.back().first==2) {
                bad_cnt-=seg.back().second;
                seg.back().first=1;
            }
            else if(seg.size()&&seg.back().first==0) {
                good_cnt--;
            }
            if(--seg.back().second==0) seg.pop_back();
        }
        else if(x=='1') {
            if(tot>1&&bad_cnt) {
                cout<<"NO"<<endl;
                return;
            }
            else {
                seg.clear();
                seg.emplace_back(0,tot);
                good_cnt=tot;
            }
        }
        else if(x=='0') {
            if((tot<=1)||(!bad_cnt&&good_cnt==tot)) {
                cout<<"NO"<<endl;
                return;
            }
            else if(seg.size()&&seg.back().first==1) {
                bad_cnt+=seg.back().second;
                seg.back().first=2;
            }
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}