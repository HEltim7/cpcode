#include<iostream>
using namespace std;
const int N=1e6+10;
int heap[N];
int siz;
// heap[1] is min
void down(int in){
    int minn=in;
    if(in*2<=siz&&heap[minn]>heap[in*2]) minn=in*2;
    if(in*2+1<=siz&&heap[minn]>heap[in*2+1]) minn=in*2+1;
    if(minn!=in){
        swap(heap[minn],heap[in]);
        down(minn);
    }
}

void up(int in){
    while(in/2&&heap[in/2]>heap[in]){
        swap(heap[in/2],heap[in]);
        in/=2;
    }
}

void remove(int in){
    heap[in]=heap[siz];
    siz--;
    down(in),up(in);
}

void edit(int in,int val){
    heap[in]=val;
    down(in),up(in);
}

void remove_root(){
    heap[1]=heap[siz];
    siz--;
    down(1);
}

void insert(int num){
    heap[++siz]=num;
    up(siz);
}

void build(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>heap[i];
    for(int i=n/2;i;i--) down(i);
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    build();
    return 0;
}