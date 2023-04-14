#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef vector<int> VI;
const int N=1e6+10;
int tr[N][26],cnt[N],ne[N],idx;
VI id,que;

inline void insert(string in){
    int fa=0;
    for(auto x:in){
        int c=x-'a';
        if(!tr[fa][c]) tr[fa][c]=++idx;
        fa=tr[fa][c];
        cnt[fa]++;
    }
    id.push_back(fa);
}

void build(){
    queue<int> q;
    for(int i=0;i<26;i++)
        if(tr[0][i]) q.push(tr[0][i]),que.push_back(tr[0][i]);
    while(q.size()){
        int t=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            int &p=tr[t][i];
            if(!p) p=tr[ne[t]][i];
            else{
                ne[p]=tr[ne[t]][i];
                q.push(p),que.push_back(p);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string in;
        cin>>in;
        insert(in);
    }
    build();
    for(int i=que.size()-1;i>=0;i--) cnt[ne[que[i]]]+=cnt[que[i]];
    for(auto x:id) cout<<cnt[x]<<endl;
    return 0;
}