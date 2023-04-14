#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int K=110;
map<LL,LL> fibo;
LL arr[K];

void solve() {
    int n;
    cin>>n;
    LL sum=0;
    for(int i=1;i<=n;i++) cin>>arr[i],sum+=arr[i];
    if(!fibo.count(sum)) {
        cout<<"NO"<<endl;
        return;
    }
    
    multiset<pair<LL,int>,greater<>> cur;
    for(int i=1;i<=n;i++) cur.emplace(arr[i],i);
    auto it=fibo.find(sum);

    int last=0;
    while(it!=fibo.begin()) {
        auto cit=cur.begin();
        if(cit->second==last) cit++;
        if(cit==cur.end()) {
            cout<<"NO"<<endl;
            return;
        }
        
        LL x;
        tie(x,last)=*cit;
        cur.erase(cit);
        x-=it->second;
        if(x<0) {
            cout<<"NO"<<endl;
            return;
        }
        if(x) cur.emplace(x,last);
        it--;
    }
    cout<<"YES"<<endl;
}

int main() {
    fibo.emplace(0,0);
    fibo.emplace(1,1);
    for(LL i=1,j=1,pre=2;pre<=LL(1e11);) {
        fibo.emplace(pre,j);
        LL k=i+j;
        i=j;
        j=k;
        pre+=j;
    }

    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}