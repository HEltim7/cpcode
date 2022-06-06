#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define endl '\n'
typedef pair<int,int> PII;
typedef vector<PII> VII;
const int N=1e5+10;

VII seg;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        seg.emplace_back(a,c);
    }
    sort(seg.begin(),seg.end());

    int ans=0;
    int lef=0xcfcfcfcf;
    for(auto [l,r]:seg){
        ans+=max(0,r-max(lef,l));
        lef=max(lef,r);
    }
    cout<<ans;
    return 0;
}

/*
3
1 342 6 34323
2 353 5 342345
3 334 4 56346
*/