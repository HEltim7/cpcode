#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

#define endl '\n'
const int N=2e5+10;
typedef pair<double,int> PDI;
struct NODE{
    int l,r,cnt,laze;
    double len;
}seg[N*4];
struct SEG{
    int l,r,h,val;
};
vector<double> num;
vector<double> deep;

inline void pushup(int id){
    if(seg[id].cnt==0) seg[id].len=seg[id<<1].len+seg[id<<1|1].len;
    else seg[id].len=num[seg[id].r]-num[seg[id].l];
}

void modify(int id,int l,int r,int val){
    auto &fa=seg[id];
    if(fa.l>=l&&fa.r<=r) fa.cnt+=val;
    else{
        int mid=fa.l+fa.r>>1;
        if(mid-1>=l) modify(id<<1,l,r,val);
        if(mid+1<=r) modify(id<<1|1,l,r,val);
    }
    pushup(id);
}

void build(int id,int l,int r){
    auto &fa=seg[id]; 
    fa={l,r};
    if(r-l==1) return;
    int mid=l+r>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid,r);
}

inline bool cmp(SEG a,SEG b){
    return a.h<b.h;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,test=0;
    while(cin>>n&&n){
        double ans=0;
        num.clear(),deep.clear();
        for(int i=1;i<=n;i++){
            double a,b,c,d;
            cin>>a>>b>>c>>d;
            num.push_back(a);
            deep.push_back(b);
            num.push_back(c);
            deep.push_back(d);
        }
        vector<double> bak1=num;
        vector<double> bak2=deep;
        vector<SEG> square;
        sort(num.begin(),num.end());
        num.erase(unique(num.begin(),num.end()),num.end());
        sort(deep.begin(),deep.end());
        deep.erase(unique(deep.begin(),deep.end()),deep.end());
        
        for(int i=0;i<bak1.size();i+=2){
            int pos[4];
            for(int j=0;j<=1;j++)
                pos[j]=lower_bound(num.begin(),num.end(),bak1[i+j])-num.begin();
            for(int j=0;j<=1;j++)
                pos[j+2]=lower_bound(deep.begin(),deep.end(),bak2[i+j])-deep.begin();
            square.push_back({pos[0],pos[1],pos[2],1});
            square.push_back({pos[0],pos[1],pos[3],-1});
        }
        sort(square.begin(),square.end(),cmp);

        build(1,0,num.size()-1);
        double last=square.front().h;
        for(auto [l,r,h,val]:square){
            double len=seg[1].len;
            ans+=len*(deep[h]-deep[last]);
            last=h;
            modify(1,l,r,val);
        }
        cout<<"Test case #"<<++test<<endl;
        cout<<"Total explored area: "<<fixed<<setprecision(2)<<ans<<endl<<endl;
    }
    return 0;
}