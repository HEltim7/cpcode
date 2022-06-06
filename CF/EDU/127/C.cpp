#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[N];
LL day[N];

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define cat(...)
#define cat_arr(...)
#endif

void solve(){
    int n;
    LL x;
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+1+n);

    LL ans=0,sum=0;
    int end=0;
    for(int i=1;i<=n;i++){
        sum+=arr[i];
        day[i]=1+(x-sum)/i;
        cat(x,sum,i,(x-sum)/i);
        if(x<sum||day[i]<=0) break;
        end=i;
    }
    
    cat_arr(day,1,n);
    cat(end);

    day[end+1]=0;
    for(int i=end;i>=1;i--)
        ans+=(day[i]-day[i+1])*i;

    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}