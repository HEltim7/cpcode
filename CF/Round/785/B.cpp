#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
bool mark[1<<7];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        memset(mark,0,sizeof mark);
        string in;
        cin>>in;
        int cnt=0;
        vector<int> pos[1<<7];
        for(auto x:in) {
            if(!mark[x]) cnt++;
            mark[x]=1;
        }
        for(int i=0;i<in.size();i++){
            pos[in[i]].push_back(i);
        }
        bool ans=1;
        for(char c='a';c<='z';c++){
            for(int i=1;i<pos[c].size();i++){
                memset(mark,0,sizeof mark);
                int tmp=0;
                for(int j=pos[c][i-1];j<=pos[c][i];j++){
                    if(!mark[in[j]]) tmp++;
                    mark[in[j]]=1;
                }
                if(tmp<cnt) ans=0;
            }
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}