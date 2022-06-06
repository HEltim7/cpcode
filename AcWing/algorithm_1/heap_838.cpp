#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int heap[N],siz;

void down(int in){
    int minn=in;
    if(in*2<=siz&&heap[minn]>heap[in*2]) minn=in*2;
    if(in*2+1<=siz&&heap[minn]>heap[in*2+1]) minn=in*2+1;
    if(minn!=in){
        swap(heap[minn],heap[in]);
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
    int n,m;
    cin>>n>>m;
    siz=n;
    for(int i=1;i<=n;i++) cin>>heap[i];
    for(int i=n/2;i;i--) down(i);
    while (m--)
    {
        cout<<heap[1]<<' ';
        remove_min();
    }
    return 0;
}