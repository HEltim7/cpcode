#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
constexpr int N=1e3+10;
LD ans[N][N][4];

LD dfs(int w,int b,int type) {
    if(ans[w][b][type]) return ans[w][b][type];
    LD res=0;
    if(type==3&&w+b==1) res=0;
    else if(w==0) res=0;
    else if(b==0) res=1;
    else {
        LD p=LD(w)/(w+b);
        if(type==1) res=p+(1-p)*(1-dfs(w,b-1,2));
        else if(type==2) res=p+(1-p)*(1-dfs(w,b-1,3));
        else res=p*dfs(w-1,b,1)+(1-p)*dfs(w,b-1,1);
    }

    return ans[w][b][type]=res;
}

void solve() {
    int w,b;
    cin>>w>>b;
    cout<<fixed<<setprecision(9)<<dfs(w,b,1)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}