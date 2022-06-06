#include <iostream>
#include <map>

using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

typedef long long LL;
typedef pair<int,int> PII;
const int N=2e5+10;
char cmd;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        int pfx1=0,pfx2=0;
        map<PII,int> m;//记录pair的数量
        m.insert({{0,0},1});
        int n;
        cin>>n;
        LL ans=0;
        for(int i=1;i<=n;i++){
            cin>>cmd;
            if(cmd=='U') pfx1++;
            else if(cmd=='D') pfx1--;
            else if(cmd=='R') pfx2++;
            else pfx2--;
            map<PII,int>::iterator it;
            it=m.find({pfx1,pfx2});
            if(it==m.end()){
                m.insert({{pfx1,pfx2},1});
            }
            else{
                it->second++;
            }
        }
        for(auto x:m){
            PII y=x.first;
            map<PII,int>::iterator it;
            it=m.find(y);
            if(it!=m.end()){
                LL tmp=it->second;
                ans+=tmp*(tmp-1)/2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

/*
7
6
URLLDR
7
RRUULLD
4
UDUD
9
RRRRRRRRL
10
UDUDUDUDUD
4
RULD
7
RLRRLUD
*/