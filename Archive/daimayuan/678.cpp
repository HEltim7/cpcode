#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;

int cnt[26],ch[2][26];
unordered_set<string> ust;
string s,na,mo;
bool ans;

void dfs(int deep,int type){
    if(ans) return;
    if(deep>=s.size()){
        if(na.size()<mo.size()) return;
        if(type){
            string tmp=na,tmo=mo;
            while(tmo.size()&&tmp.back()==tmo.back())
                tmp.pop_back(),tmo.pop_back();
            if(na.size()!=mo.size()+tmp.size()) return;
            if(ust.count(tmp)) ans=1;
        }
        else{
            string tmp;
            for(int i=0;i<na.size();i++)
                if(i>=mo.size()||na[i]!=mo[i])
                    tmp.push_back(na[i]);
            if(na.size()!=mo.size()+tmp.size()) return;
            ust.insert(tmp);
        }
        return;
    }

    int t=s[deep]-'a';
    if(ch[0][t]+1<=cnt[t]){
        na.push_back(s[deep]);
        ch[0][t]++;
        dfs(deep+1,type);
        ch[0][t]--;
        na.pop_back();
    }
    
    if(ch[1][t]+1<=cnt[t]){
        mo.push_back(s[deep]);
        ch[1][t]++;
        dfs(deep+1,type);
        ch[1][t]--;
        mo.pop_back();
    }
}

void init(){
    ust.clear();
    ans=0;
    memset(cnt,0,sizeof cnt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        init();
        string l,r;
        cin>>l;
        for(auto x:l) cnt[x-'a']++;
        bool flag=0;
        for(int i=0;i<26;i++){
            if(cnt[i]&1) flag=1;
            cnt[i]>>=1;
        }
        while(l.size()&&l.size()!=r.size()) r.push_back(l.back()),l.pop_back();
        reverse(r.begin(),r.end());
        if(!l.size()) flag=1;
        if(flag){
            cout<<"impossible"<<endl;
            continue;
        }

        s=l;
        ans=0;
        dfs(0,0);
        s=r;
        dfs(0,1);
        if(ans) cout<<"possible"<<endl;
        else cout<<"impossible"<<endl;
    }
    return 0;
}