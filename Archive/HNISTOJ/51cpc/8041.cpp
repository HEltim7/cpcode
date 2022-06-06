#include<iostream>
using namespace std;
const int N=1e6+10;
int heap[N];
int siz;

void down(int in){
    int minn=in;
    if(in*2<=siz&&heap[in*2]<heap[minn]) minn=in*2;
    if(in*2+1<=siz&&heap[in*2+1]<heap[minn]) minn=in*2+1;
    if(minn!=in){
        swap(heap[in],heap[minn]);
        down(minn);
    }
}

void remove_min(){
    heap[1]=heap[siz];
    siz--;
    down(1);
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin>>n;
    siz=n;
    for(int i=1;i<=n;i++) cin>>heap[i];
    for(int i=n/2;i;i--) down(i);
    while(n--){
        cout<<heap[1]<<' ';
        remove_min();
    }
    return 0;
}