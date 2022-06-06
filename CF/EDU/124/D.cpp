#include<iostream>
#include<queue>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<random>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int,int> PII;
const int N=2e5+10,M=1e6;
map<PII,PII> ans;
unordered_map<LL,bool> poi;
LL rnd;

struct QUE {
    int row,col,step;
};
queue<QUE> q;

inline LL get(int row,int col){
    return row*rnd+col;
}

int mvr[]={1,-1,0,0};
int mvc[]={0,0,1,-1};
inline bool full(int row,int col){
    int cnt=0;
    for(int i=0;i<4;i++) 
        if(poi.find(get(row+mvr[i],col+mvc[i]))!=poi.end())
            cnt++;
    return cnt==4;
}

void bfs(){
    while(q.size()){
        auto [row,col,step]=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int r=row+mvr[i];
            int c=col+mvc[i];
            if(poi.find(get(r,c))!=poi.end()&&poi[get(r,c)]==0){
                if(step==0)
                    ans.insert({{r,c},{row,col}});
                else{
                    auto last=ans[{row,col}];
                    ans.insert({{r,c},last});
                }
                q.push({r,c,step+1});
                poi[get(r,c)]=1;
            }
        }
    }
}

int main() {
    // freopen64("hack.txt","r",stdin);
    // freopen64("out.txt","w",stdout);
    mt19937 gen(time(0));
    rnd=gen()%M+M;
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    PII read[N];
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        read[i]={a,b};
        poi.emplace(get(a,b),0);
    }
    unordered_set<LL> ust;
    for(int i=1;i<=n;i++){
        if(!full(read[i].first,read[i].second)){
            for(int j=0;j<4;j++){
                int row=read[i].first+mvr[j];
                int col=read[i].second+mvc[j];
                if(poi.find(get(row,col))==poi.end()
                    &&ust.find(get(row,col))==ust.end())
                    q.push({row,col,0}),ust.emplace(get(row,col));
            }
        }
    }
    bfs();
    for(int i=1;i<=n;i++){
        cout<<ans[read[i]].first<<' '<<ans[read[i]].second<<endl;
    }
    return 0;
}

/*
hack数据：

1. 纯map,约3.3秒
________________________________________________________
Executed in    3.29 secs    fish           external
   usr time    3.26 secs  239.00 micros    3.26 secs
   sys time    0.02 secs   62.00 micros    0.02 secs

2. 哈希,TLE,10分钟没跑出来


3. 随机化哈希,约1.7秒
________________________________________________________
Executed in    1.74 secs    fish           external
   usr time    1.72 secs    0.00 micros    1.72 secs
   sys time    0.02 secs  401.00 micros    0.02 secs

*/