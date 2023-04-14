#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int INF=1e9;
int arr[10];

void solve() {
    int n;
    while(cin>>n) {
        int ans=INF;
        while(n--) {
            auto get=[&](string &s) {
                int h=(s[0]-'0')*10+s[1]-'0';
                int m=(s[3]-'0')*10+s[4]-'0';
                return h*60+m;
            };

            string s;
            cin>>s;
            int start=get(s);
            cin>>s;
            int finish=get(s);
            cin>>s;
            int arrival=get(s);

            int m;
            cin>>m;
            for(int i=1;i<=m;i++) cin>>arr[i];
            
            auto f=[&](int x,int y) {
                LL xx=1,sum=0;
                for(int i=1;i<=m;i++) {
                    sum+=arr[i]*xx;
                    xx*=x;
                }
                LL res=floor(abs(y*sin(sum)));
                return res;
            };
        
            for(int i=max(arrival,start);i<=finish;i++) {
                int x=i-start;
                int y=finish-start;
                int t=i+f(x,y);
                if(t<=finish) ans=min(ans,t);
            }
        }

        auto get=[&](int x) {
            string h=to_string(x/60);
            string m=to_string(x%60);
            if(h.size()<2) h="0"+h;
            if(m.size()<2) m="0"+m;
            return h+":"+m;
        };

        if(ans<INF) cout<<get(ans)<<endl;
        else cout<<"Oh No!"<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}