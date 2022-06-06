#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PLI=pair<LL,int>;
const int N=2e5+10;
int n,m,p,q;
PLI arr[N];
LL pre[N];
int ans[N],isok[N];

inline bool check1(int l,int r){
    LL sum=pre[r]-pre[l-1];
    return arr[r].first*(r-l+1)*q<=p*sum;
}

inline bool check2(int x,int l,int r){
    LL sum=pre[r]-pre[l-1];
    return arr[r].first*m*q<=(arr[x].first+sum)*p;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i].first,arr[i].second=i;
    cin>>p>>q;
    sort(arr+1,arr+1+n);
    for(int i=1;i<=n;i++) pre[i]=arr[i].first+pre[i-1];

    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=l+r>>1;
            if(check1(mid,i)) r=mid;
            else l=mid+1;
        }
        ans[i]=i-l+1;
        m=max(m,i-l+1);
    }

    for(int i=1;i<=n;i++){
        if(ans[i]==m){
            int lim=i-m+1;
            int l=1,r=lim;
            while(l<r){
                int mid=l+r>>1;
                if(check2(mid,lim+1,i)) r=mid;
                else l=mid+1;
            }
            isok[l]++,isok[i+1]--;
        }
    }

    vector<int> num;
    for(int i=1,sum=0;i<=n;i++){
        sum+=isok[i];
        if(sum==0) num.push_back(arr[i].second);
    }

    cout<<num.size()<<endl;
    sort(num.begin(),num.end());
    for(auto x:num) cout<<x<<' ';
    return 0;
}