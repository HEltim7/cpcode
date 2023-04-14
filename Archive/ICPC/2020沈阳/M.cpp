#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

#ifdef __LOCAL
#include<debug>
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string s;
    cin>>s;
    int idx1=0,idx2=-1,len=0;
    cout<<idx1+1<<' '<<idx1+len+1<<endl;
    for(int i=1;i<s.size();i++){
        if(s[i]>s[idx1]) idx1=i,len=0,idx2=-1;
        else if(idx2!=-1){
            if(s[idx1+len+1]<s[i]) idx1=idx2,len++,idx2=-1;
            else if(s[idx1+len+1]==s[i]) idx1=idx2,idx2=-1,len=0;
            else idx2=-1,len=0;
        }
        else if(s[i]==s[idx1]) idx2=i,len=0;
        // debug(idx1,len,idx2);
        cout<<idx1+1<<' '<<i+1<<endl;
    }
    return 0;
}