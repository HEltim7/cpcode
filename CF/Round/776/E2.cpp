#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=2e5+10,INF=0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        vector<int> date=vector<int>(n+1,0);
        date[0]=0;
        for(int i=1;i<=n;i++) cin>>date[i];

        int muse=INF,maxleni=1,aimidx=0,cnt=0;
        for(int i=1;i<=n;i++) {
            int t=date[i]-date[i-1]-1;
            if(muse>t) muse=t,cnt=1,aimidx=i;
            if(t>date[maxleni]-date[maxleni-1]-1) maxleni=i;
        }

        vector<int> tmp;
        if(maxleni>=aimidx) maxleni --;
        date.erase(date.begin()+aimidx);
        for(int i=0;i<date.size();i++) {
            if(i==maxleni) tmp.push_back(date[i-1]+(date[i]-date[i-1])/2),tmp.push_back(date[i]);
            else tmp.push_back(date[i]);
        }
        int res=INF;
        if(date.back()!=d) res=d-date.back();
        for(int i=1;i<=n;i++) res=min(res,tmp[i]-tmp[i-1]-1);
        cout<<max(muse,res)<<endl;
        
    }
    return 0;
}