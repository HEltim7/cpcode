#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,m;
    string s;
    cin>>n>>m;

    auto cal_min=[&]() {
        int two=m/4;
        for(int i=1;i<m&&two;) {
            if(s[i]=='1'&&s[i+1]=='1') two--,i+=2;
            else i++;
        }
        return m/4-two;
    };

    auto cal_max=[&]() {
        int two=m/4;
        for(int i=1;i<m&&two;) {
            if(!(s[i]=='1'&&s[i+1]=='1')) two--,i+=2;
            else i++;
        }
        return two;
    };

    int minn=0,maxx=0;
    for(int i=1;i<=n;i++) {
        cin>>s;
        s=" "+s;
        int tot=0;
        for(int i=1;i<=m;i++) tot+=s[i]=='1';
        minn+=tot-cal_min();
        maxx+=tot-cal_max();
    }
    
    cout<<minn<<' '<<maxx<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}