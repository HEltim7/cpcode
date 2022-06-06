#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[N];
int preout[N][2];
int prefit[N][2];

inline bool checkr(int a,int b){
    return  preout[b][1]-preout[a-1][1]==0&&
            preout[b][0]-preout[a-1][0]==0;
}

inline bool checkl(int a,int b){
    return  prefit[b][1]-prefit[a-1][1]>0&&
            prefit[b][0]-prefit[a-1][0]>0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,x,y;
    cin>>n>>x>>y;
    LL ans=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        prefit[i][1]+=prefit[i-1][1]+(x==arr[i]);
        prefit[i][0]+=prefit[i-1][0]+(y==arr[i]);
        preout[i][1]+=preout[i-1][1]+(arr[i]>x);
        preout[i][0]+=preout[i-1][0]+(arr[i]<y);
    }

    for(int i=1;i<=n;i++){
        int l=i,r=n;
        while(l<r){
            int mid=l+r+1>>1;
            if(checkr(i,mid)) l=mid;
            else r=mid-1;
        }
        int R=l;
        l=i,r=n;
        while(l<r){
            int mid=l+r>>1;
            if(checkl(i,mid)) r=mid;
            else l=mid+1;
        }
        int L=l;
        
        if(checkl(i,L)&&checkr(i,R)) ans+=max(0,R-L+1);
    }
    cout<<ans;
    return 0;
}