#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1<<7;
int ch[N];

inline void cal(string s[]){
    int cnt[2][N];
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<2;i++)
        for(auto x:s[i]) cnt[i][x]++;
    for(auto i='a';i<='z';i++)
        ch[i]+=max(cnt[0][i],cnt[1][i]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s[2];
        cin>>s[0]>>s[1];
        cal(s);
    }
    for(auto i='a';i<='z';i++)
        cout<<ch[i]<<endl;
    return 0;
}