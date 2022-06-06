#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        vector<int> num;
        for(int i=1;i<=n;i++){
            int in;
            cin>>in;
            num.push_back(in);
        }
        sort(num.begin(),num.end());
        num.erase(unique(num.begin(),num.end()),num.end());
        if(num.front()>1){
            cout<<"No"<<endl;
            continue;
        }
        int maxx=num.back();
        vector<int> mis,has;
        unordered_set<int> st;
        bool ans=1;
        int last=0;
        for(auto &x:num) {
            for(int i=last+1;i<x;i++) {
                mis.push_back(i);
                int lim=maxx/i;
                for(auto &y:has){
                    if(y==1) continue;
                    if(y>lim) break;
                    else for(int j=i*y;j<i*y+y;j++) st.insert(j);
                }
            }
            int lim=maxx/x;
            for(auto &y:mis) {
                if(y>lim) break; 
                else for(int i=x*y;i<x*y+x;i++) st.insert(i);
            }
            has.push_back(x);
            last=x;
            if(st.find(x)!=st.end()){
                ans=0;
                break;
            }
        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}