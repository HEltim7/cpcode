#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;

const int N=210;
int n,m;
int in;
unordered_set<int> pack,mirror;
unordered_set<int>::iterator iter;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>in;
        mirror=pack;
        for(auto x:mirror){
            pack.insert(x+in);
        }
        pack.insert(in);
    }
    int minn=5e4;
    for(auto x:pack){
        if(x>=m) minn=min(x,minn);
    }
    cout<<minn;
    return 0;
}