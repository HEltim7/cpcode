#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=3e5+10;

int n,m='z';
string s;
int fir[N],sec[N],cnt[N];
int sa[N],rk[N],height[N];

void get_sa(){
    for(int i=1;i<=n;i++) cnt[fir[i]=s[i]]++;
    for(int i=2;i<=m;i++) cnt[i]+=cnt[i-1];
    for(int i=n;i;i--) sa[cnt[fir[i]]--]=i;

    for(int k=1;k<=n;k<<=1){
        int num=0;
        for(int i=n-k+1;i<=n;i++) sec[++num]=i;
        for(int i=1;i<=n;i++) if(sa[i]>k) sec[++num]=sa[i]-k;
        for(int i=1;i<=m;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) cnt[fir[i]]++;
        for(int i=2;i<=m;i++) cnt[i]+=cnt[i-1];
        for(int i=n;i;i--) sa[cnt[fir[sec[i]]]--]=sec[i],sec[i]=0;
        swap(fir,sec);
        fir[sa[1]]=num=1;
        for(int i=2;i<=n;i++)
            fir[sa[i]]=(sec[sa[i]]==sec[sa[i-1]]&&sec[sa[i]+k]==sec[sa[i-1]+k])
                ?num:++num;
        if(num==n) break;
        m=num;
    }
}

void get_height(){
    for(int i=1;i<=n;i++) rk[sa[i]]=i;
    for(int i=1,k=0;i<=n;i++){
        if(rk[i]==1) continue;
        if(k) k--;
        int j=sa[rk[i]-1];
        while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k]) k++;
        height[rk[i]]=k;
    }
}

const LL INF=0x3f3f3f3f3f3f3f3f;
using PLL=pair<LL,LL>;

int fa[N],val[N],sz[N];
LL max1[N],max2[N],min1[N],min2[N];
vector<int> hs[N];
PLL ans[N];
LL num,maxv=-INF;

int findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

inline LL get(int x){
    return 1LL*x*(x-1)/2;
}

PLL update(int r){
    for(auto x:hs[r]){
        int a=findfa(x-1),b=findfa(x);
        num-=get(sz[a])+get(sz[b]);
        fa[a]=b;
        sz[b]+=sz[a],sz[a]=0;
        num+=get(sz[b]);

        LL tmp1[]={max1[a],max2[a],max1[b],max2[b]};
        sort(tmp1,tmp1+4,greater<LL>());
        max1[b]=tmp1[0],max2[b]=tmp1[1];
        
        LL tmp2[]={min1[a],min2[a],min1[b],min2[b]};
        sort(tmp2,tmp2+4);
        min1[b]=tmp2[0],min2[b]=tmp2[1];

        maxv=max({maxv,max1[b]*max2[b],min1[b]*min2[b]});
    }
    if(maxv==-INF) return {num,0};
    else return {num,maxv};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++) cin>>val[i];
    get_sa(),get_height();
    for(int i=2;i<=n;i++) hs[height[i]].push_back(i);
    
    for(int i=1;i<=n;i++){
        fa[i]=i;
        sz[i]=1;
        max1[i]=min1[i]=val[sa[i]];
        max2[i]=-INF,min2[i]=INF;
    }

    for(int i=n-1;i>=0;i--) ans[i]=update(i);
    for(int i=0;i<=n-1;i++) cout<<ans[i].first<<' '<<ans[i].second<<endl;
    return 0;
}