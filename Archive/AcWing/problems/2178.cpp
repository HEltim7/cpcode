#include<iostream>
#include<vector>
#include<cmath>
#include<set>
using namespace std;

#define endl '\n'
const int N=60;
typedef pair<int,int> PII;
vector<int> pillar[N];
set<PII,greater<PII>> st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) st.insert({0,i});
    for(int i=1;;i++){
        bool flag=0;
        for(auto [val,id]:st){
            int x=sqrt(val+i);
            if(val==0||val+i==x*x){
                st.erase({val,id});
                st.insert({i,id});
                pillar[id].push_back(i);
                flag=1;
                ans++;
                break;
            }
        }
        if(!flag) break;
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        for(auto x:pillar[i]) cout<<x<<' ';
        cout<<endl;
    }
    return 0;
}