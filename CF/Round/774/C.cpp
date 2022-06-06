#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<map>
#include<cassert>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
const LL MAX=1e12;
vector<LL> item;
unordered_map<LL,LL> mp;

inline LL cntbit(LL x){
    LL res=0;
    while(x){
        if(x&1) res++;
        x>>=1;
    }
    return res;
}

void init(){
    LL num=1,idx=2;
    while(num<=MAX){
        item.push_back(num);
        num*=idx++;
    }
    for(auto x:item){
        vector<pair<LL,LL>> tmp;
        for(auto [sum,step]:mp){
            tmp.push_back({sum+x,step+1});
        }
        for(auto y:tmp) {
            if(mp.find(y.first)==mp.end()) mp.insert(y);
            else mp.insert({y.first,max(y.second,mp[y.first])});
        }
        if(cntbit(x)>1) mp.insert({x,1});
    }
}

//a<b?
inline bool check(LL a,LL b){
    return ((a^b)&a)==0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    int t;
    cin>>t;
    while(t--){
        LL aim;
        LL maxx=0,maxy=0;
        cin>>aim;
        for(auto [sum,step]:mp){
            if(aim>=sum&&cntbit(aim-sum)+step<cntbit(aim-maxx)+maxy){
                maxx=sum;
                maxy=step;
            }
        }
        aim-=maxx;
        cout<<cntbit(aim)+maxy<<endl;
    }
    return 0;
}