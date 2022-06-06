#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
const int N=1010,INF=0x3f3f3f3f;
int tr[N][4],ne[N],idx;
int getn[1<<7],dp[N][N];
bool cnt[N];

inline void insert(string s){
    int fa=0;
    for(auto x:s){
        if(!tr[fa][getn[x]]) tr[fa][getn[x]]=++idx;
        fa=tr[fa][getn[x]];
    }
    cnt[fa]=1;
}

void build(){
    queue<int> q;
    for(int i=0;i<4;i++)
        if(tr[0][i]) q.push(tr[0][i]);
    while(q.size()){
        int t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            if(!tr[t][i]) tr[t][i]=tr[ne[t]][i];
            else{
                ne[tr[t][i]]=tr[ne[t]][i];
                q.push(tr[t][i]);
                cnt[tr[t][i]]|=cnt[tr[ne[t]][i]];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,T=0;
    getn['A']=0,getn['G']=1,getn['C']=2,getn['T']=3;
    while(cin>>n&&n){
        memset(tr,0,sizeof tr);
        memset(ne,0,sizeof ne);
        memset(cnt,0,sizeof cnt);
        memset(dp,0x3f,sizeof dp);
        idx=0;
        string gen;
        for(int i=1;i<=n;i++){
            cin>>gen;
            insert(gen);
        }
        cin>>gen;
        gen=" "+gen;
        build();
        //dp[i][j]=到字符串前i位，AC自动机匹配到j位置，合法修改量的最小值
        dp[0][0]=0;
        for(int i=1;i<gen.size();i++) //枚举字符串位置
            for(int j=0;j<idx;j++) //枚举AC自动机位置
                for(int k=0;k<4;k++){ //枚举决策
                    //如果字符串字符与决策相同，无需修改
                    int cost=getn[gen[i]]!=k;
                    //如果状态合法，更新状态
                    if(!cnt[tr[j][k]])
                        dp[i][tr[j][k]]=min(dp[i][tr[j][k]],dp[i-1][j]+cost);
                }
        int ans=INF;
        for(int i=0;i<=idx;i++) ans=min(ans,dp[gen.size()-1][i]);
        cout<<"Case "<<++T<<": "<<(ans==INF?-1:ans)<<endl;
    }
    return 0;
}