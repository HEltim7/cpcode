#include<iostream>
#include<map>
#include<unordered_map>
#include<unordered_set>
using namespace std;

typedef long long LL;
const int N=5e5+10;
LL pfx[N];
typedef map<LL,LL> MLL;
typedef unordered_map<LL,MLL> MAP;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL n,m;
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++) scanf("%lld",&pfx[i]),pfx[i]+=pfx[i-1];
        LL mod=pfx[n]>0?pfx[n]:-pfx[n];

        if(mod==0){
            map<LL,LL> map;
            for(int i=1;i<=n;i++) map.emplace(pfx[i],i);
            for(int i=1;i<=m;i++){
                LL query;
                scanf("%lld",&query);
                if(query==0){
                    printf("%d\n",0);
                    continue;
                }
                if(map.find(query)==map.end()) printf("%d\n",-1);
                else printf("%lld\n",map.find(query)->second);
            }
            continue;
        }

        MAP map;
        for(int i=1;i<=n;i++){
            MAP::iterator it=map.find((pfx[i]%mod+mod)%mod);
            if(it==map.end()){
                map.emplace((pfx[i]%mod+mod)%mod,MLL());
                map.find((pfx[i]%mod+mod)%mod)->second.emplace(pfx[i],i);
            }
            else {
                auto &t=it->second;
                if(t.find(pfx[i])==t.end())
                    t.emplace(pfx[i],i);
            }
        }

        for(int i=1;i<=m;i++){
            LL query;
            scanf("%lld",&query);
            if(query==0){
                printf("%d\n",0);
                continue;
            }
            MAP::iterator it=map.find((query%mod+mod)%mod);
            if(pfx[n]>0){
                if(it!=map.end()){
                    auto res=it->second.upper_bound(query);
                    if(res!=it->second.begin()){
                        res--;
                        LL tmp=res->first;
                        LL loc=res->second;
                        printf("%lld\n",(query-tmp)/mod*n+loc);
                    }
                    else printf("%d\n",-1);
                }
                else printf("%d\n",-1);
            }
            else{
                if(it!=map.end()){
                    auto res=it->second.lower_bound(query);
                    if(res!=it->second.end()){
                        LL tmp=res->first;
                        LL loc=res->second;
                        printf("%lld\n",(query-tmp)/mod*(-1)*n+loc);
                    }
                    else printf("%d\n",-1);
                }
                else printf("%d\n",-1);
            }
        }
    }
    return 0;
}