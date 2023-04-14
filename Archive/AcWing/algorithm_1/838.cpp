#include<iostream>
using namespace std;

const int N=1e5+10;
int heap[N],idx;

void up(int loc){
    while(loc/2&&heap[loc/2]>heap[loc]){
        swap(heap[loc],heap[loc/2]);
        loc/=2;
    }
}

void down(int loc){
    int minn=loc;
    if(loc*2<=idx&&heap[minn]>heap[loc*2]) minn=loc*2;
    if(loc*2+1<=idx&&heap[minn]>heap[loc*2+1]) minn=loc*2+1;
    if(minn!=loc){
        swap(heap[minn],heap[loc]);
        down(minn);
    }
}

void insert(int x){
    heap[++idx]=x;
    up(idx);
}

void pop(){
    swap(heap[idx],heap[1]);
    idx--;
    down(1);
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        insert(x);
    }
    while(m--){
        cout<<heap[1]<<' ';
        pop();
    }
    return 0;
}