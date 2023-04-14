#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

#define PII pair<int,int>

const int N=1e5+10;
int a[N],b[N];
unordered_map<int,int> mpa;
unordered_map<int,int> mpb;
unordered_map<int,int>::iterator iter;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m,aim;
    cin>>n>>m>>aim;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mpa.insert(PII(a[i],i));
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
        mpb.insert(PII(b[i],i));
    }
    for(int i=0;i<n;i++){
        iter=mpb.find(aim-a[i]);
        if(iter!=mpb.end()){
            cout<<i<<' '<<iter->second;
            return 0;
        }
    }
    return 0;
}