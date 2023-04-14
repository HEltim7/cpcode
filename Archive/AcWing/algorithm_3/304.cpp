#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef vector<int> VI;
typedef long double LD;
const int N=1e5+10;

string str[N];
int n,l,p;
LL pfx[N],last[N];
LD dp[N];
struct SEG{
    int l,r,val;
}res[N];

inline LD qpow(LD a,LL b){
    LD res=1;
    while(b){
        if(b&1) res=res*a;
        b>>=1;
        a=a*a;
    }
    return res;
}

LD cal(int x,int k){
    LD len=abs(pfx[x]-pfx[k]+x-k-1-l);
    return dp[k]+qpow(len,p);
}

inline bool cmp(int a,int b,int x){
    return cal(x,a)<=cal(x,b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>l>>p;
        for(int i=1;i<=n;i++){
            cin>>str[i];
            pfx[i]=pfx[i-1]+str[i].size();
        }
        
        int hh=1,tt=1;
        res[hh]={1,n,0};
        for(int i=1;i<=n;i++){
            int best=res[hh].val;
            last[i]=best;
            dp[i]=cal(i,best);
            if(res[hh].r<=i) hh++;
            int pos=-1;
            while(hh<=tt&&cmp(i,res[tt].val,res[tt].l)) pos=res[tt--].l;
            if(hh<=tt&&cmp(i,res[tt].val,res[tt].r)){
                auto [l,r,val]=res[tt];
                while(l<r){
                    int mid=l+r>>1;
                    if(cmp(i,val,mid)) r=mid;
                    else l=mid+1;
                }
                res[tt].r=l-1;
                pos=l;
            }
            if(pos!=-1) res[++tt]={pos,n,i};
        }

        VI ans;
        for(int i=n;i;i=last[i]) ans.push_back(i);
        reverse(ans.begin(),ans.end());
        if(dp[n]<=1e18){
            cout<<(LL)dp[n]<<endl;
            int idx=1;
            for(auto x:ans){
                while(idx<x) cout<<str[idx++]<<' ';
                cout<<str[idx++];
                cout<<endl;
            }
        }
        else cout<<"Too hard to arrange"<<endl;
        cout<<"--------------------"<<endl;
    }
    return 0;
}

/*
1
18 50 3                                  
mpwuxwyaqu
ifmtgopqvvexxaodve
oqamkzkkabfpjmdfsswlprpo
rcvmihb
jpn
axldecmrgtlaqwphleaf
vrreutokgzmempkod
wxnwnjmwxsycauvtasnqetrqzdfk
inqhcnumbtltrpvnkrocgeg
wybbdnvocmvf
stclexcvssfjgkpmsrkrumwjjmlxks
claprxtmsludt
vgyosrieo
qcgnmzmqko
eo
sgomjiseorsiicpyxfbe
pdggpxntlomtdaentjdmdlw
axffylanoivefjzsznl

输出:
决策更新:
0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 
0 0 0 0 0 2 2 2 2 2 2 2 2 2 2 2 2 2 
0 0 0 0 0 3 3 3 3 3 3 3 3 3 3 3 3 3 
0 0 0 0 0 3 3 4 4 4 4 4 4 4 4 4 4 4 
0 0 0 0 0 3 3 5 5 5 5 5 5 5 5 5 5 5 
0 0 0 0 0 3 3 6 6 6 6 6 6 6 6 6 6 6 
0 0 0 0 0 3 3 6 7 7 7 7 7 7 7 7 7 7 
0 0 0 0 0 3 3 6 7 7 8 8 8 8 8 8 8 8 
0 0 0 0 0 3 3 6 7 7 9 9 9 9 9 9 9 9 
0 0 0 0 0 3 3 6 7 7 9 9 10 10 10 10 10 10 
0 0 0 0 0 3 3 6 7 7 9 9 10 11 11 11 11 11 
0 0 0 0 0 3 3 6 7 7 9 9 10 11 11 12 12 12 
0 0 0 0 0 3 3 6 7 7 9 9 10 11 11 12 13 13 
0 0 0 0 0 3 3 6 7 7 9 9 10 11 11 12 13 14 
0 0 0 0 0 3 3 6 7 7 9 9 10 11 11 12 15 15 
0 0 0 0 0 3 3 6 7 7 9 9 10 11 11 12 15 16 
0 0 0 0 0 3 3 6 7 7 9 9 10 11 11 12 15 16 
0 0 0 0 0 3 3 6 7 7 9 9 10 11 11 12 15 16 
答案:
974
mpwuxwyaqu ifmtgopqvvexxaodve oqamkzkkabfpjmdfsswlprpo 
rcvmihb jpn axldecmrgtlaqwphleaf vrreutokgzmempkod 
wxnwnjmwxsycauvtasnqetrqzdfk inqhcnumbtltrpvnkrocgeg 
wybbdnvocmvf stclexcvssfjgkpmsrkrumwjjmlxks claprxtmsludt 
vgyosrieo qcgnmzmqko eo sgomjiseorsiicpyxfbe 
pdggpxntlomtdaentjdmdlw axffylanoivefjzsznl 
--------------------
决策:
0 0 0 0 0 3 3 6 7 7 9 9 10 11 11 12 15 16
*/