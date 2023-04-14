#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define endl '\n'
const int N=5e5+10;
int h[N],fa[N],son[N],tail[N];
int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            h[i]=i;
            tail[i]=i;
            son[i]=-1;
            fa[i]=-1;
        }
        
        while(m--){
            int a,b;
            cin>>a>>b;
            if(h[a]==-1&&h[b]==-1){
                continue;
            }
            else if(h[a]==-1){
                h[a]=tail[b];
                tail[a]=h[b];
                h[b]=-1;
                tail[b]=-1;
            }
            else if(h[b]==-1){
                swap(h[a],tail[a]);
            }
            else{
                if(son[tail[a]]==-1) son[tail[a]]=h[b];
                else fa[tail[a]]=h[b];

                if(son[h[b]]==-1) son[h[b]]=tail[a];
                else fa[h[b]]=tail[a];

                tail[a]=h[a];
                h[a]=tail[b];//a的头<-b的尾
                
                h[b]=-1;
                tail[b]=-1;
            }
        }

        vector<int> res;
        int now=h[1],last=-2;
        if(now==-1){
            cout<<0<<endl;
            continue;
        }
        for(;;){
            res.push_back(now);
            int s=son[now];
            int f=fa[now];
            if(s==-1&&f==-1) break;
            if(f!=-1&&f!=last){
                last=now;
                now=f;
            }
            else if(s!=-1&&s!=last){
                last=now;
                now=s;
            }
            else break;
        }
        
        cout<<res.size()<<' ';
        for(auto x:res) cout<<x<<' ';
        cout<<endl;
    }
    return 0;
}