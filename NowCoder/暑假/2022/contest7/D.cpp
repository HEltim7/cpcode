#include <array>
#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
constexpr int N=5,INF=0x3f3f3f3f;
using LL=long long;
using PII=pair<int,char>;
using Hand=array<PII,N>;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <debug>
#else
#define debug(...)
#endif

int dp[1<<6][1<<6];
bool st[1<<6][1<<6];
PII card[20]; //[0-5]公共牌，[6-7] Alice [8-9] Bob

//abc是Alice的决策
int check(int a,int b,int c) {
    Hand alice={},bob={};
    alice={card[6],card[7],card[a],card[b],card[c]};
    bob={card[8],card[9]};
    for(int i=0,idx=2;i<6;i++,assert(idx<=N)) if(i!=a&&i!=b&&i!=c) bob[idx++]=card[i];
    sort(alice.begin(),alice.end());
    sort(bob.begin(),bob.end());
    
    for(int i=0;i<N;i++) debug(alice[i]);
    for(int i=0;i<N;i++) debug(bob[i]);

    auto get_pair=[](Hand &x,array<int,5> &res) {
        int cnt=0;
        for(int i=0;i<N;i++) 
            if(i&&x[i].first==x[i-1].first) cnt++;
            else res[cnt]++,cnt=1;
        if(cnt>=2) res[cnt]++;
    };

    auto check_flush=[](Hand &x) {
        char suit=x[0].second;
        for(int i=1;i<N;i++) if(suit!=x[i].second) return 0;
        return 1;
    };

    auto check_straight=[](Hand &x) {
        bool flag=1;
        for(int i=1;i<N;i++) if(x[i].first!=x[i-1].first+1) flag=0;
        if(x[0].first==2&&x[1].first==3&&x[2].first==4&&x[3].first==5&&x[4].first==14) flag=1;
        return flag;
    };

    auto get_type=[&](Hand &x,array<int,N> &p) {
        get_pair(x,p);
        int pair_cnt=p[2]+p[3]+p[4];
        bool isstraight=check_straight(x);
        bool isflush=check_flush(x);
        debug(isstraight,isflush);
        debug(p[2],p[3],p[4]);
        if(isflush&&isstraight&&x[0].first==10) return 10;
        else if(isflush&&isstraight) return 9;
        else if(p[4]) return 8;
        else if(p[3]&&p[2]) return 7;
        else if(isflush&&!pair_cnt) return 6;
        else if(isstraight) return 5;
        else if(p[3]) return 4;
        else if(p[2]==2) return 3;
        else if(p[2]) return 2;
        return 1;
    };

    array<int,N> pa={},pb={};
    int atype=get_type(alice,pa);
    int btype=get_type(bob,pb);
    debug(atype,btype);
    if(atype!=btype) return atype>btype?1:-1;
    else {
        array<int,N> a,b;
        for(int i=N-1,idx=0;i>=0;i--) a[idx++]=alice[i].first;
        for(int i=N-1,idx=0;i>=0;i--) b[idx++]=bob[i].first;
        if(atype==9||atype==5) {
            if(a[0]==14) a={5,4,3,2,1};
            if(b[0]==14) b={5,4,3,2,1};
        }

        auto rank_sort=[](array<int,N> &x,array<int,N> &p) {
            array<int,N> res;
            int idx=0;
            for(int i=4;i>=2;i--)
                if(p[i]) {
                    int cnt=0;
                    for(int j=0;j<N;j++) {
                        if(j&&x[j]==x[j-1]) cnt++;
                        else {
                            if(cnt==i)
                                for(int k=0;k<i;k++) res[idx++]=x[j-1];
                            cnt=1;
                        }
                    }
                    if(cnt==i) for(int k=0;k<i;k++) res[idx++]=x[N-1];
                }
            debug(idx);
            for(int i=0;i<N;i++) if((i==0||x[i]!=x[i-1])&&(i==N-1||x[i]!=x[i+1])) res[idx++]=x[i];
            debug(idx);
            assert(idx==N);
            return res;
        };

        if(atype==8||atype==7||atype==4||atype==3||atype==2) {
            a=rank_sort(a,pa);
            b=rank_sort(b,pb);
        }

        for(int i=0;i<N;i++) debug(a[i]);
        for(int i=0;i<N;i++) debug(b[i]);

        if(a>b) return 1;
        else if(a<b) return -1;
        return 0;
    }
}

int dfs(int x,int y,int len)//先手状态为x，后手状态为y
{
    if(st[x][y]) return dp[x][y];
    st[x][y]=true;
    if(len==3)
    {  
        vector<int> ver;//Alice选的哪几张牌

        for(int i=0;i<6;i++) if(x>>i&1) ver.push_back(i);
        assert(ver.size()==3);
        debug(ver,check(ver[0],ver[1],ver[2]));
        return dp[x][y]=check(ver[0],ver[1],ver[2]);
    }

    int ans=-INF;//Alice的决策
    for(int i=0;i<6;i++)//Alice选牌
    {
        if((x>>i&1)||(y>>i&1)) continue;

        int A=(x^(1<<i));
        int now=INF;
        for(int j=0;j<6;j++)//Bob选牌
        {
            if((y>>j&1)||(x>>j&1)||i==j) continue;

            int B=(y^(1<<j));
            now=min(now,dfs(A,B,len+1));
        }

        ans=max(ans,now);
    }
    return dp[x][y]=ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(st,false,sizeof st);
        string a1,a2,b1,b2;
        cin>>a1>>a2>>b1>>b2;
        card[6].first=a1[0];card[6].second=a1[1];
        card[7].first=a2[0];card[7].second=a2[1];
        card[8].first=b1[0];card[8].second=b1[1];
        card[9].first=b2[0];card[9].second=b2[1];
        for(int i=0;i<6;i++)
        {
            string ci;
            cin>>ci;
            card[i].first=ci[0];
            card[i].second=ci[1];
        }
        for(int i=0;i<10;i++)
        {
            if(card[i].first>='0'&&card[i].first<='9') card[i].first-='0';
            else if(card[i].first=='T') card[i].first=10;
            else if(card[i].first=='J') card[i].first=11;
            else if(card[i].first=='Q') card[i].first=12;
            else if(card[i].first=='K') card[i].first=13;
            else if(card[i].first=='A') card[i].first=14;
        }
        int res=dfs(0,0,0);
        if(res==1) puts("Alice");
        else if(res==0) puts("Draw");
        else if(res=-1)puts("Bob");
        else
        {
            vector<int> ver(1e9);
        }
    }
}
