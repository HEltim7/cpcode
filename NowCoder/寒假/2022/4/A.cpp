#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
typedef vector<int> VI;
VI R;
LL ans;

inline void add(int k){
    if(R.size()<k) return;
    VI pre;
    int last=0;
    for(auto x:R) pre.push_back(last+x),last=last+x;
    for(int i=0,j=0;i<pre.size();i++){
        int pos=lower_bound(pre.begin()+i,pre.end(),k+j)-pre.begin();
        ans+=max(0,(int)pre.size()-pos);
        if(R[i]==1) j++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        char c;
        cin>>c;
        if(c=='R') R.push_back(1);
        else if(c!='P') R.push_back(0);
        else add(k),R.clear(); 
    }
    add(k);
    cout<<ans;
    return 0;
}