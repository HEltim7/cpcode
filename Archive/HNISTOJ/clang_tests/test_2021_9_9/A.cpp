#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<int,int> m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,in;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>in,m.emplace(in,i);
    cin>>in;
    auto ans=m.find(in);
    if(ans!=m.end())
        cout<<"R["<<m.find(in)->second<<"]="<<m.find(in)->first;
    else cout<<"R[-1]="<<in;
    return 0;
}