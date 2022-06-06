#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e4+10,M=1e6+10,S=51;
int tr[N*S][26],cnt[N*S],ne[N*S];
int ans,idx;

inline void insert(string &str){
    int fa=0;
    for(auto x:str){
        int t=x-'a';
        if(!tr[fa][t]) tr[fa][t]=++idx;
        fa=tr[fa][t];
    }
    cnt[fa]++;
}

void build(){
    queue<int> q;
    for(int i=0;i<26;i++)
        if(tr[0][i]) q.push(tr[0][i]);
    while(q.size()){
        int t=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            int c=tr[t][i];
            if(!c) tr[t][i]=tr[ne[t]][i];
            else{
                ne[c]=tr[ne[t]][i];
                q.push(c);
            }
            // if(!c) continue;
            // int j=ne[t];
            // while(j&&!tr[j][i]) j=ne[j];
            // if(tr[j][i]) j=tr[j][i];
            // ne[c]=j;
            // q.push(c);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,n;
    string str;
    cin>>t;
    while(t--){
        memset(tr,0,sizeof tr);
        memset(cnt,0,sizeof cnt);
        memset(ne,0,sizeof ne);
        idx=ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>str;
            insert(str);
        }
        build();
        cin>>str;
        int j=0;
        for(auto x:str){
            int t=x-'a';
            j=tr[j][t];
            // while(j&&!tr[j][t]) j=ne[j];
            // if(tr[j][t]) j=tr[j][t];

            int p=j;
            while(p){
                ans+=cnt[p];
                cnt[p]=0;
                p=ne[p];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}