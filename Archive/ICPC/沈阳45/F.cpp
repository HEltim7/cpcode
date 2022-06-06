#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e3+10;
int g[1<<7];
char str[N];
int n;

string encode(int r){
    for(int i=0;i<30;i++) g[i]=-1;
    int dif=0;
    for(int i=r;i>=1;i--){
        int t=str[i]-'a';
        if(g[t]==-1) g[t]=dif++;
    }
    string res;
    for(int i=1;i<=r;i++){
        int t=str[i]-'a';
        res.push_back(g[t]+'a');
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>str[i];
    vector<string> ans;
    for(int i=1;i<=n;i++) ans.push_back(encode(i));
    sort(ans.begin(),ans.end());
    cout<<ans.back()<<endl;
    return 0;
}