#include<iostream>
using namespace std;

const int N=1e5+10;
int loc[N],siz,idx; // loc存第k个数在heap的下标
struct HEAP
{
    int data;
    int id;
}heap[N];

void up(int in){
    while(in/2&&heap[in/2].data>heap[in].data){
        swap(loc[heap[in].id],loc[heap[in/2].id]);
        swap(heap[in],heap[in/2]);
        in/=2;
    }
}

void down(int in){
    int  minn=in; 
    if(in*2<=siz&&heap[in*2].data<heap[minn].data) minn=in*2;
    if(in*2+1<=siz&&heap[in*2+1].data<heap[minn].data) minn=in*2+1;
    if(in!=minn){
        swap(loc[heap[in].id],loc[heap[minn].id]);
        swap(heap[in],heap[minn]);
        down(minn);
    }
}

void insert(int x){
    heap[++siz].data=x;
    heap[siz].id=++idx;
    loc[idx]=siz;
    up(siz);
}

void pop(){
    swap(loc[heap[1].id],loc[heap[siz].id]);
    swap(heap[1],heap[siz--]);
    down(1);
}

void delete_k(int k){
    int loc_k=loc[k];
    swap(loc[k],loc[heap[siz].id]);
    swap(heap[loc_k],heap[siz--]);
    down(loc_k),up(loc_k);
}

void modify(int k,int x){
    heap[loc[k]].data=x;
    down(loc[k]),up(loc[k]);
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        string op;
        int k,x;
        cin>>op;
        if(op=="I"){
            cin>>x;
            insert(x);
        }
        else if(op=="D"){
            cin>>k;
            delete_k(k);
        }
        else if(op=="C"){
            cin>>k>>x;
            modify(k,x);
        }
        else if(op=="PM"){
            cout<<heap[1].data<<'\n';
        }
        else{
            pop();
        }
    }
    return 0;
}