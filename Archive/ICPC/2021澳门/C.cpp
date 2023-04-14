#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
double eps=1e-8;

inline bool cmp(double a, double b){
    return a-b>eps;
}

inline bool equ(double a,double b){
    return abs(a-b)<=eps;
}

inline int in_axis(vector<double> &v,double k){
    auto it=lower_bound(v.begin(),v.end(),k-eps,cmp);
    int res=0;
    while(it!=v.end()){
        if(equ(*it,k)) res++,it=next(it);
        else break;
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    int ans=n;
    vector<double> poi[5];
    int x_axis,y_axis;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        if(x==0) y_axis++;
        else if(y==0) x_axis++;
        else{
            if(x>0&&y>0) poi[1].push_back((double)y/x);
            else if(x<0&&y>0) poi[2].push_back((double)y/-x);
            else if(x<0&&y<0) poi[3].push_back((double)y/x);
            else poi[4].push_back((double)-y/x);
        }
    }

    if(x_axis){
        int t=poi[1].size()+poi[2].size();
        ans=min({ans,t,n-t-x_axis});
    }
    if(y_axis) {
        int t=poi[1].size()+poi[4].size();
        ans=min({ans,t,n-t-y_axis});
    }
    
    int allin[]={0,2,3,4,1};
    for(int i=1;i<=4;i++){
        for(auto k:poi[i]){
            int res=poi[allin[i]].size();
            int axis=in_axis(poi[i],k);
            if(i==1||i==3){
                int t=upper_bound(poi[1].begin(),poi[1].end(),k)-poi[1].begin();
                res+=poi[1].size()-t;
                res+=upper_bound(poi[3].begin(),poi[3].end(),k)
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}