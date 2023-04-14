#include<iostream>
using namespace std;

#define endl '\n'
const int N=1e6+10;
int ne[N];
char s[N],p[N];

void get_next(int n){
    ne[0]=ne[1]=0;
    for(int i=2,j=0;i<=n;i++){
        while(j&&p[i]!=p[j+1]) j=ne[j];
        if(p[i]==p[j+1]) j++;
        ne[i]=j;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string str;
    str=" chuanzhi";
    int n=str.size()-1;
    for(int i=1;i<=n;i++) p[i]=str[i];
    get_next(n);
    cin>>str;
    str=" "+str;
    int m=str.size()-1;
    for(int i=1;i<=m;i++) s[i]=str[i];

    int ans=0;
    for(int i=1,j=0;i<=m;i++){
        while(j&&s[i]!=p[j+1]) j=ne[j];
        if(s[i]==p[j+1]) j++;
        if(j==n){
            ans++;
            j=ne[j];
        }
    }
    cout<<ans;
    return 0;
}