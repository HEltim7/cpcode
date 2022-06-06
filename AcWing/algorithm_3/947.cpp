#include<iostream>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;

typedef long long LL;
const int N=2e6+10;

int main() {
    crope r;
    int t,a,cur=0;
    cin>>t;
    while(t--){
        string op;
        char str[N];
        cin>>op;
        if(op=="Insert"){
            cin>>a;
            for(int i=0;i<a;i++) {
                str[i]=getchar();
                if(str[i]=='\n') i--;
            }
            str[a]='\0';
            r.insert(cur,str);
        }
        else if(op=="Delete"){
            cin>>a;
            r.erase(cur,a);
        }
        else if(op=="Get"){
            cin>>a;
            cout<<r.substr(cur,a)<<endl;
        }
        else if(op=="Move"){
            cin>>a;
            cur=a;
        }
        else if(op=="Prev") cur--;
        else cur++;
    }
    return 0;
}