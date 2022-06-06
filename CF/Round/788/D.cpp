#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

#define endl '\n'
using LL=long long;

map<int,int> res;

void init() {
    int n=1e9;
    int cnt=0,ans=0;
    int line[]={0,0,0};
    int idx=0;
    while(cnt<n){
        line[idx]++;
        ans++;
        cnt+=(line[(idx+1)%3]+line[(idx+2)%3])*2;
        idx=(idx+1)%3;
        res.emplace(cnt,ans);
    }
}

void sovle(){
    int n;
    cin>>n;
    cout<<res.lower_bound(n)->second<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    int t;
    cin>>t;
    while(t--) sovle();
    return 0;
}