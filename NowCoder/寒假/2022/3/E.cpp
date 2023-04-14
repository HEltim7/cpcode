#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10,mod=1e9+7;

int color[N],num[N];

LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    string in;
    cin>>in;
    reverse(in.begin(),in.end());
    in=" "+in;
    for(int i=1;i<in.size();i++) num[i]=in[i]-'0';
    for(int i=n;i>=1;i--) cin>>color[i];

    for(int z=0;z<=k;z++){
        vector<int> nums;
        LL ans=0;
        int last;
        for(int i=1;i<=n+1;i++){
            if(nums.empty()) nums.push_back(num[i]),last=i;
            else if(color[i]==color[last]) nums.push_back(num[i]);
            else{
                sort(nums.begin(),nums.end());
                for(LL x:nums){
                    ans=(ans+x*qpow(10,last-1)%mod)%mod;
                    last++;
                }
                nums.clear();
                nums.push_back(num[i]);
                last=i;
            }
        }

        cout<<ans<<endl;
        if(z<k){
            int p,q;
            cin>>p>>q;
            for(int i=1;i<=n;i++) 
                if(color[i]==p) color[i]=q;
        }
    }
    return 0;
}