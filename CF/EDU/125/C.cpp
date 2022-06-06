#include<vector>
#include<iostream>
#include<algorithm>
#include<random>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=5e5+10,mod=1e9+7,P=131;
int rnd;
LL arr[N];

inline LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
    
}

// #define __LOCAL
#ifdef __LOCAL
#include<debug>
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    mt19937 gen(time(0));
    rnd=gen()%77;
    int A=7+rnd,B=rnd;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            char c;
            cin>>c;
            if(c=='(') arr[i]=A;
            else arr[i]=B;
        }
        int l=1,cnt=0;
        int ans=0,lef=n;
        bool flag=1;
        LL lhash=0,rhash=0;
        for(int r=1;r<=n;r++){
            if(arr[r]==A) cnt++;
            else cnt--;
            if(cnt<0) flag=0;
            if(l==r) continue;
            else if(l+1==r){
                lhash=arr[l];
                rhash=arr[r];
                
                if(cnt==0&&flag||lhash==rhash){
                    debug(l,r);
                    ans++;
                    lef-=(r-l+1);
                    l=r+1;
                    flag=1;
                    cnt=0;
                }
            }
            else{
                int mid=l+r>>1;
                int len=mid-l-1;
                if((r-l+1)&1) {
                    rhash=(rhash-arr[mid]*qpow(P,len)%mod+mod)%mod;
                }
                else lhash=(lhash+arr[mid]*qpow(P,len+1)%mod)%mod;
                rhash=(rhash*P%mod+arr[r])%mod;

                debug(lhash,rhash);

                if(cnt==0&&flag||lhash==rhash){
                    debug(l,r);
                    ans++;
                    lef-=(r-l+1);
                    l=r+1;
                    flag=1;
                    cnt=0;
                }
            }
        }
        cout<<ans<<' '<<lef<<endl;
    }
    return 0;
}