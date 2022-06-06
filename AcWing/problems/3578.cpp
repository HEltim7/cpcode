#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=2e5+10;
int num[N];
int n,add;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);
    cin>>n>>add;
    for(int i=1;i<=n;i++) cin>>num[i];
    if(n==1){
        cout<<num[1]+add;
        return 0;
    }
    sort(num+1,num+1+n);

    int l=n/2+1,r=n;
    while(l<=r){
        int mid=l+r>>1;
        int res=0;
        for(int i=n/2+1;i<=mid;i++) res+=num[mid]-num[i];
        if(res==add){
            cout<<num[mid];
            return 0;
        }
        else if(res<add){
            l=mid+1;
        }
        else if(res>add){
            r=mid;
        }
    }
    while(num[r]==num[r+1]) r++;
    for(int i=n/2+1;i<=r;i++){
        add-=num[r]-num[i];
    }
    int ans=num[r]+add/(r-n/2);
    cout<<ans;
    return 0;
}