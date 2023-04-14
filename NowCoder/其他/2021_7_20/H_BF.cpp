#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string ans;
    int n,k;
    cin>>n>>k;

    if(k==0){
        if(n%2==0){
            for(int i=1;i<=n/2;i++) cout<<'A';
            for(int i=1;i<=n/2;i++) cout<<'B';
        }
        else{
            for(int i=1;i<=n/2;i++) cout<<'A';
            for(int i=1;i<=n/2+1;i++) cout<<'B';
            cout<<endl;
            for(int i=1;i<=n/2+1;i++) cout<<'A';
            for(int i=1;i<=n/2;i++) cout<<'B';
        }
        return 0;
    }

    int cases=(n-k)*k;
    int bigone=0,smallone=0;

    while((bigone+1)*k<=cases/2){
        bigone++;
        ans+='A';
    }
    smallone=cases/2-bigone*k;
    ans+='B';

    for(int i=1;i<=smallone;i++) ans+='A';

    for(int i=1;i<=k-smallone-1;i++) ans+='B';

    ans+='A';
    for(int i=ans.length();i<n;i++) ans+='B';

    if(cases%2==0){
        cout<<ans<<endl;
        ans="";
        bigone=0,smallone=0;

        while((bigone+1)*k<=cases/2+1){
            bigone++;
            ans+='A';
        }
        smallone=cases/2+1-bigone*k;
        ans+='B';

        for(int i=1;i<=smallone;i++) ans+='A';

        for(int i=1;i<=k-smallone-1;i++) ans+='B';

        ans+='A';
        for(int i=ans.length();i<n;i++) ans+='B';
    }

    cout<<ans;
    return 0;
}