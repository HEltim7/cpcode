#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=300;
int c[N];
int d[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s,t,ans;
        cin>>s>>t;
        memset(c,0,sizeof c);
        for(auto x:s) c[x]++;
        if(c[t[0]]==0||c[t[1]]==0||c[t[2]]==0){
            for(int i='a';i<='z';i++){
                for(int j=1;j<=c[i];j++) ans+=(char)i;
            }
        }
        else if(t[0]<=t[1]&&t[1]<=t[2]){
            for(int i='a';i<='z';i++){
                if(i==t[1]){
                    for(int j=1;j<=c[t[2]];j++) ans+=(char)t[2];
                    c[t[2]]=0;
                    for(int j=1;j<=c[t[1]];j++) ans+=(char)t[1];
                }
                else for(int j=1;j<=c[i];j++) ans+=(char)i;
            }
        }
        else{
            for(int i='a';i<='z';i++){
                for(int j=1;j<=c[i];j++) ans+=(char)i;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}