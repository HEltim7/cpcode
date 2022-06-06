#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using ULL=unsigned long long;

int ans=100,n;
ULL val[110],aim=1;
bool num[110][10];

void get(ULL x,int idx) {
    for(int i=2;i<=9;i++) num[idx][i]=0;
    while(x) {
        num[idx][x%10]=1;
        x/=10;
    }
}

int fn(ULL x) {
    int res=0;
    while(x<aim) x*=9,res++;
    return res;
}

void dfs(int deep) {
    if(deep+fn(val[deep])>=ans) return;
    if(val[deep]>=aim) {
        ans=min(ans,deep);
        return;
    }
    get(val[deep],deep);
    for(int i=9;i>=2;i--) {
        if(num[deep][i]) {
            val[deep+1]=val[deep]*i;
            dfs(deep+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n;
    cin>>val[0];
    for(int i=1;i<n;i++) aim*=10;
    dfs(0);
    cout<<(ans==100?-1:ans);
    return 0;
}