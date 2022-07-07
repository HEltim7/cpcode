#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1440+10;
int cnt[N];
bool mark[N];

void init() {
    for(int i=0;i<1440;i++) {
        int hh=i/60;
        int mm=i%60;
        string h,m;
        if(hh<10) h="0"+to_string(hh);
        else h=to_string(hh);
        if(mm<10) m="0"+to_string(mm);
        else m=to_string(mm);
        reverse(m.begin(),m.end());
        cnt[i]=h==m;
    }
}

int get(string hh,string mm) {
    int res=0;
    res+=(hh.back()-'0')*60;
    res+=(hh.front()-'0')*600;
    res+=(mm.back()-'0');
    res+=(mm.front()-'0')*10;
    return res;
}

void solve() {
    string hh,mm;
    int t;
    char in;
    cin>>in;
    hh.push_back(in);
    cin>>in;
    hh.push_back(in);
    cin>>in>>in;
    mm.push_back(in);
    cin>>in;
    mm.push_back(in);
    cin>>t;
    int cur=get(hh,mm);
    int ans=0;
    memset(mark,0,sizeof mark);
    for(int i=0;i<=1440;cur=(cur+t)%1440) {
        if(mark[cur]) break;
        ans+=cnt[cur];
        mark[cur]=1;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    init();
    while(t--) solve();
    return 0;
}