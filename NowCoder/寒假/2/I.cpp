#include<iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
string str="!\"'*+-.08:^_WTYUIOAHXVM|=";

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    string ans;
    if(m==36){
        cout<<-1;
        return 0;
    }
    if(n<=11){
        if(n<m){
            cout<<-1;
            return 0;
        }
    }
    else {
        int maxx=10;
        maxx+=(n-10+1)/2;
        maxx=min(maxx,35);
        if(maxx<m){
            cout<<-1;
            return 0;
        }
    }
    if(n&1) ans.push_back('='),m--,n--;
    if(m>=2) ans="<"+ans+">",m-=2,n-=2;
    if(m>=2) ans="["+ans+"]",m-=2,n-=2;
    if(m>=2) ans="("+ans+")",m-=2,n-=2;
    if(m>=2) ans="{"+ans+"}",m-=2,n-=2;
    if(m>=2) ans="\\"+ans+"/",m-=2,n-=2;

    if(m==0){
        string l,r;
        char x=ans[ans.length()/2];
        char y=x;
        if(x=='>') y='<';
        else if(x=='<') y='>';
        for(int i=0;i<n;i+=2) l+=x,r+=y;
        ans=l+ans+r;
        cout<<ans;
        return 0;
    }
    else{
        string l,r;
        int idx=0;
        for(int i=1;i<=m;i++,n-=2) l+=str[idx],r=str[idx]+r,idx++;
        char x=l[0];
        for(int i=0;i<n;i+=2) l+=x;
        ans=l+ans;
        if(x=='>') x='<';
        else if(x=='<') x='>';
        for(int i=0;i<n;i+=2) ans+=x;
        ans+=r;
        cout<<ans;
        return 0;
    }
    return 0;   
}

/*

12 6
11 6
100 35
*/