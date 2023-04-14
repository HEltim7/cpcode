#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,ans=0;
    cin>>n;
    if(n==1){
        cout<<1;
        return 0;
    }
    vector<int> cow,boll;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        cow.push_back(in);
    }
    sort(cow.begin(),cow.end());
    for(int i=0;i<cow.size();i++){
        if(i==0) boll.push_back(1);
        else if(i==cow.size()-1) boll.push_back(-1);
        else if(cow[i+1]-cow[i]<cow[i]-cow[i-1]) boll.push_back(1);
        else boll.push_back(-1);
    }
    for(int i=0;i<n-1;i++){
        if(boll[i]==1&&boll[i+1]==-1){
            int cnt=0;
            if(i-1>=0&&boll[i-1]==1) cnt++;
            if(i+2<n&&boll[i+2]==-1) cnt++;
            if(cnt==2) ans+=cnt;
            else ans++;
            i++;
        }
    }
    cout<<ans;
    return 0;
}