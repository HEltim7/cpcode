#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> num(n+1),ans;
        map<int,int> mp;
        for(int i=1;i<=n;i++){
            cin>>num[i];
            if(mp.find(num[i])!=mp.end()) mp[num[i]]++;
            else mp.emplace(num[i],1);
        }
        bool flag=0;
        for(auto [a,b]:mp)
            if(b&1) flag=1;
        if(flag){
            cout<<-1<<endl;
            continue;
        }

        int cnt=0;
        vector<pair<int,int>> res;
        while(num.size()>1){
            int end=2;
            while(num[1]!=num[end]) end++;
            for(int i=2;i<end;i++) res.push_back({cnt+end+i-2,num[i]});
            ans.push_back((end-1)*2);
            cnt+=(end-1)*2;
            reverse(num.begin()+2,num.begin()+end);
            num.erase(num.begin()+end),num.erase(num.begin()+1);
        }
        cout<<res.size()<<endl;
        for(auto [a,b]:res) cout<<a<<' '<<b<<endl;
        cout<<ans.size()<<endl;
        for(auto x:ans) cout<<x<<' ';
        cout<<endl;
    }
    return 0;
}