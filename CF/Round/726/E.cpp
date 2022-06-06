#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s,ans;
    int k,n;
    cin>>n>>k;
    cin>>s;
    int i=0,j=0;
    for(j=1;j<n-1;){
        if(s[i]>s[j]) j++,i=0;
        else if(s[i]<s[j]) break;
        else while(s[i]==s[j]) i++,j++;
    }
    j=j-i;
    int x=0;
    for(int i=0;i<k;i++,x++){
        if(x>=j) x=0;
        ans+=s[x];
    }
    cout<<ans;
    return 0;
}