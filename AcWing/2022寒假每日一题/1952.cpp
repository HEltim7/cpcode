#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define endl '\n'
typedef pair<int,int> PII;
typedef vector<PII> VII;
const int N=20000*2+10;

int n,x,y,z,ans;
int res[N];
VII cow;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>x>>y>>z;
    vector<int> num;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        b++;
        num.push_back(a);
        num.push_back(b);
        cow.push_back({a,b});
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    res[0]+=x*n;
    for(auto [a,b]:cow){
        a=upper_bound(num.begin(),num.end(),a)-num.begin();
        b=upper_bound(num.begin(),num.end(),b)-num.begin();
        res[a]+=y-x;
        res[b]+=z-y;
    }
    int tmp=0;
    for(int i=0;i<=num.size();i++){
        tmp+=res[i];
        ans=max(tmp,ans);
    }
    cout<<ans;
    return 0;
}