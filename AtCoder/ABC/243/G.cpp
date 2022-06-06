#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
typedef unsigned long long ULL;
const int N=1e5+10;
ULL M=3e9;

struct SEG { 
    int begin; 
    ULL add,start; 
};
vector<SEG> v;

void init(){
    //idx实际位置，获取增量
    //segidx线段位置，segidx->idx
    //当前和,更新start


    int segidx=0,idx=3;
    ULL sum=5;
    int cnt=5;
    v.emplace_back(2,1,2);
    for(int i=2;i<N;i++){
        ULL add=(idx-v[segidx].begin)*v[segidx].add+v[segidx].start;
        // v.emplace(sum,);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        ULL x;
        cin>>x;
    }
}