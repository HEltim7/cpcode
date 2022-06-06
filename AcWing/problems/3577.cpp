#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
int n,m;
const int N=210;
int num[N];
set<int> a,b;
set<int>::iterator iter;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);
    cin>>n;
    int in;
    for(int i=1;i<=n;i++){
        cin>>in;
        a.insert(in);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>in;
        b.insert(in);
    }
    for(auto i:a){
        for(auto j:b){
            if(a.find(i+j)==a.end()&&b.find(i+j)==b.end()){
                cout<<i<<' '<<j;
                return 0;
            }
        }
    }
    return 0;
}