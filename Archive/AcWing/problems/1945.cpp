#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef vector<int> VI;
VI cow;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    int in;
    for(int i=1;i<=n;i++) cin>>in,cow.push_back(in);
    sort(cow.begin(),cow.end());
    int ans=0;
    for(int i=0;i<cow.size()-2;i++){
        for(int j=i+1;j<cow.size()-1;j++){
            int dis=cow[j]-cow[i];
            int l=lower_bound(cow.begin(),cow.end(),cow[j]+dis)-cow.begin();
            int r=upper_bound(cow.begin(),cow.end(),cow[j]+2*dis)-cow.begin();
            ans+=r-l;
        }
    }
    cout<<ans;
    return 0;
}