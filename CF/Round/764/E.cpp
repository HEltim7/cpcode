#include<iostream>
#include<unordered_map>
#include<tuple>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef tuple<int,int,int> TIII;
const int N=1e3+10;

unordered_map<string,TIII> res;
int dp[N];//3表示从-3转移过来,2表示从-2转移过来
string in;

inline string get2(int idx){
    string tmp="";
    tmp.push_back(in[idx]);
    tmp.push_back(in[idx+1]);
    return tmp;
}

inline string get3(int idx){
    return get2(idx)+in[idx+2];
}

int main() {
    freopen64("E.in","r",stdin);
    freopen64("E.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,n,m;
    cin>>t;
    while(t--){
        res.clear();
        cin>>n>>m;
        memset(dp,0,sizeof (int)*(m+1));
        for(int i=1;i<=n;i++){
            cin>>in;
            for(int j=0;j<m-1;j++){
                string tmp=get2(j);
                res.insert({tmp,{i,j+1,j+2}});
                if(j+2<m){
                    tmp=get3(j);
                    res.insert({tmp,{i,j+1,j+3}});
                }
            }
        }
        cin>>in;
        if(m==1){
            cout<<"-1"<<endl;
            continue;
        }
        for(int i=1;i<m;i++){
            if((i==1||dp[i-2])&&res.find(get2(i-1))!=res.end())
                dp[i]=2;
            else if((i==2||i-3>=0&&dp[i-3])&&res.find(get3(i-2))!=res.end())
                dp[i]=3;
        }
        if(dp[m-1]){
            int idx=m-1;
            vector<TIII> ans;
            while(idx>0){
                if(dp[idx]==2){
                    ans.push_back(res[get2(idx-1)]);
                    idx-=2;
                }
                else{
                    ans.push_back(res[get3(idx-2)]);
                    idx-=3;
                }
            }
            reverse(ans.begin(),ans.end());
            cout<<ans.size()<<endl;
            for(auto [id,l,r]:ans) cout<<l<<' '<<r<<' '<<id<<endl;
        }
        else cout<<"-1"<<endl;
    }
}