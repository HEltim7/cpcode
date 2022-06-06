#include<iostream>
#include<set>
using namespace std;

#define endl '\n'
typedef long long LL;
int mvr[]={-1,-2,-2,-1,1,2,2,1};
int mvc[]={-2,-1,1,2,2,1,-1,-2};
set<pair<int,int>> st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL a,b,c,d;
    cin>>a>>b>>c>>d;
    for(int i=0;i<8;i++)
        st.insert({a+mvr[i],b+mvc[i]});
    for(int i=0;i<8;i++){
        pair<int,int> t={c+mvr[i],d+mvc[i]};
        if(st.find(t)!=st.end()){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}