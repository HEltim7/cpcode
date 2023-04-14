//数组单链表
#include<iostream>
using namespace std;
const int N=100000+10;
int head,idx,ne[N],e[N];

void init(){
    head=-1;
    idx=1;
}

//插入至链表头部
void add_to_head(int x){
    e[idx]=x;
    ne[idx]=head;
    head=idx;
    idx++;
}

//插入到k后
void add_to_k(int k,int x){
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx;
    idx++;
}

//删除k后的点
void remove_k(int k){
    ne[k]=ne[ne[k]];
}

int main(){
    init();
    int n,k,x;
    char op;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>op;
        if(op=='H'){
            scanf("%d",&x);
            add_to_head(x);
        }
        else if(op=='D'){
            scanf("%d",&k);
            if(k==0)
                head=ne[head];
            else
                remove_k(k);
        }
        else{
            scanf("%d%d",&k,&x);
            add_to_k(k,x);
        }
    }
    idx=head;
    while(idx!=-1){
        cout<<e[idx]<<' ';
        idx=ne[idx];
    }
    return 0;
}