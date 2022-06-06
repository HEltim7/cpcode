#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> wall;
    wall.reserve(n+2);
    int min1=1e8,min2=1e8;
    for(int i=1;i<=n;i++) {
        cin>>wall[i];
        int cur=(wall[i]+1)/2;
        if(cur<=min1) {
            min2=min1;
            min1=cur;
        }
        else if(cur<min2) min2=cur;
    }
    debug(min1,min2);
    int ans=min1+min2;

    for(int i=2;i<=n;i++){
        int a=wall[i-1];
        int b=wall[i];
        if(a<b) swap(a,b);
        int res=0;
        int t=a-b;
        if(b<t){
            res=(a+1)/2;
            ans=min(ans,res);
            continue;
        }
        else res=t,b-=t,a=b;
        t=a/3;
        res+=t*2;
        a-=t*3,b-=t*3;
        res+=a;
        ans=min(ans,res);
    }

    for(int i=3;i<=n;i++){
        int a=wall[i-2];
        int b=wall[i];
        if(a<b) swap(a,b);
        int res=b;
        a-=b;
        res+=(a+1)/2;
        ans=min(ans,res);
    }
    cout<<ans<<endl;
    return 0;
}