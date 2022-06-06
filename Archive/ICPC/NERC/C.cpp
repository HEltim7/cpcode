#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

LL x[4],y[4];
int ans;
vector<vector<int>> res;
inline int len(int a,int b){
    return abs(x[a]-x[b])+abs(y[a]-y[b]);
}

inline void print(int a,int b){
    if(x[a]==x[b]&&y[a]==y[b]) return;
    if(x[a]==x[b]||y[a]==y[b]) {
        ans++;
        vector<int> tmp;
        tmp.push_back(x[a]);
        tmp.push_back(y[a]);
        tmp.push_back(x[b]);
        tmp.push_back(y[b]);
        res.push_back(tmp);
        // cout<<x[a]<<' '<<y[a]<<x[b]<<' '<<y[b]<<endl;
    }
    else{
        ans+=2;
        vector<int> tmp;
        tmp.push_back(x[a]);
        tmp.push_back(y[a]);
        tmp.push_back(x[b]);
        tmp.push_back(y[a]);
        res.push_back(tmp);
        tmp.clear();
        tmp.push_back(x[b]);
        tmp.push_back(y[a]);
        tmp.push_back(x[b]);
        tmp.push_back(y[b]);
        res.push_back(tmp);
        // cout<<x[a]<<' '<<y[a]<<' '<<x[b]<<' '<<y[a]<<endl;
        // cout<<x[b]<<' '<<y[a]<<' '<<x[b]<<' '<<y[b]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    for(int i=1;i<=3;i++) cin>>x[i]>>y[i];
    LL a=len(1,2)+len(2,3);//1-3
    LL b=len(2,3)+len(1,3);//1-2
    LL c=len(1,2)+len(1,3);//2-3
    if(a==min({a,b,c})) print(1,2),print(2,3);
    else if(b==min({a,b,c})) print(2,3),print(1,3);
    else print(1,2),print(1,3);
    cout<<ans<<endl;
    for(auto v:res){
        for(auto x:v) cout<<x<<' ';
        cout<<endl;
    }
    return 0;
}
/*
0 0
2 4
4 0q
*/