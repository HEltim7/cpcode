#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int,int> PII;
const int N=1010;
int num[N];
PII cow[N];

inline int cal(){
    int cnt=0,res=0;
    for(int i=0;i<=1000;i++){
        if(cnt) res++;
        cnt+=num[i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        num[a]++,num[b]--;
        cow[i]={a,b};
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        auto [a,b]=cow[i];
        num[a]--,num[b]++;
        ans=max(ans,cal());
        num[a]++,num[b]--;
    }
    cout<<ans;
    return 0;
}