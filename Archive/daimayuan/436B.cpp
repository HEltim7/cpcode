#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int,int> PII;
const int N=500000+10;
LL ans;
LL minn[N],maxx[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<PII> mins,maxs;
    for(int i=0;i<n;i++){
        int in;
        cin>>in;
        if(mins.empty()){
            mins.push_back({in,1});
            maxs.push_back({in,1});
            maxx[i]=minn[i]=in;
            continue;
        }
        
        int cnt=0;
        if(in>=maxs.back().first){
            int l=0,r=maxs.size()-1,t=maxs.size();
            while(l<r){
                int mid=l+r>>1;
                if(maxs[mid].first>in) l=mid+1;
                else r=mid;
            }
            for(int j=l;j<t;j++) cnt+=maxs.back().second,maxs.pop_back();
            maxs.push_back({in,++cnt});
            maxx[i]=1LL*in*cnt+(i-cnt>=0?maxx[i-cnt]:0);
            minn[i]=minn[i-1]+in;
            mins.push_back({in,1});
        }
        else{
            int l=0,r=mins.size()-1,t=mins.size();
            while(l<r){
                int mid=l+r>>1;
                if(mins[mid].first<in) l=mid+1;
                else r=mid;
            }
            for(int j=l;j<t;j++) cnt+=mins.back().second,mins.pop_back();
            mins.push_back({in,++cnt});
            minn[i]=1LL*in*cnt+(i-cnt>=0?minn[i-cnt]:0);
            maxx[i]=maxx[i-1]+in;
            maxs.push_back({in,1});
        }
        ans+=maxx[i]-minn[i];
    }
    cout<<ans;
    return 0;
}