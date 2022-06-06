#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=500000+10;
LL ans;
int minn[N],maxx[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> mins,maxs;
    for(int i=0;i<n;i++){
        int in;
        cin>>in;
        if(mins.empty()){
            mins.push_back(in);
            maxs.push_back(in);
            maxx[i]=minn[i]=in;
            continue;
        }
        
        if(in>=maxs.back()){
            int l=0,r=i-1;
            while(l<r){
                int mid=l+r>>1;
                if(maxs[mid]>in) l=mid+1;
                else r=mid;
            }
            for(int j=l;j<i;j++) maxs[j]=in,maxx[j]=maxx[j-1]+in;
        }
        else{
            int pos=upper_bound(mins.begin(),mins.end(),in)-mins.begin();
            for(int j=pos;j<i;j++) mins[j]=in,minn[j]=minn[j-1]+in;
        }
        ans+=maxx[i-1]-minn[i-1];
        maxs.push_back(in),mins.push_back(in);
        maxx[i]=maxx[i-1]+in,minn[i]=minn[i-1]+in;
    }
    cout<<ans;
    return 0;
}