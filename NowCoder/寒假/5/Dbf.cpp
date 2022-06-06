#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;

inline bool check(LL x){
    if(x==0||x==1) return 0;
    for(LL i=2;i<=x/i;i++)
        if(x%i==0) return 0;
    return 1;
}

inline bool ck(LL x){
    if(x==1) return 1;
    if(x<10) return 0;
    vector<int> num;
    while(x){
        num.push_back(x%10);
        x/=10;
    }
    bool one=0;
    for(auto x:num) if(x==1) one=1;
    if(one==0) return 0;
    for(int i=0;i<num.size()-1;i++)
        if(!check(num[i]+num[i+1])) one=0;
    return one;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL l,r;
    cin>>l>>r;
    LL ans=0;
    for(LL i=l;i<=r;i++){
        if(ck(i)) ans++;
    }
    cout<<ans;
    return 0;
}
