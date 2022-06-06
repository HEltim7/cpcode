#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int alpha,beta,garma,n;
    int a_backup,b_backup,g_backup;
    cin>>alpha>>beta>>garma>>n;
    a_backup=alpha,b_backup=beta,g_backup=garma;
    alpha=min(min(a_backup,b_backup),g_backup);
    garma=max(max(a_backup,b_backup),g_backup);
    beta=a_backup+b_backup+g_backup-alpha-garma;

    string s1,s2,s3;
    for(int i=1;i<=alpha;i++) s1+='a',s2+='a',s3+='a';
    for(int i=alpha+1;i<=beta;i++) s2+='b',s3+='b',s1+='x';
    for(int i=beta+1;i<=garma+beta-alpha;i++) s1+='c',s3+='c',s2+='y';
    for(int i=garma+beta-alpha+1;i<=n;i++) s1+='x',s2+='y',s3+='z';

    if(s1.length()>n){
        cout<<"NO";
        return 0;
    }

    if(a_backup==alpha){
        if(b_backup==beta) cout<<s1<<endl<<s2<<endl<<s3;
        else cout<<s2<<endl<<s1<<endl<<s3;
    }
    else if(a_backup==beta){
        if(b_backup==alpha) cout<<s3<<endl<<s2<<endl<<s1;
        else cout<<s2<<endl<<s3<<endl<<s1;
    }
    else{
        if(b_backup==alpha) cout<<s3<<endl<<s1<<endl<<s2;
        else cout<<s1<<endl<<s3<<endl<<s2;
    }

    return 0;    
}