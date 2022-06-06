#include<iostream>
#include<cstring>
using namespace std;

const int N=1e5+10;
int num[N],idx=1;
int ne[N],le[N],h,t;

void insert_head(int x){
    if(h==0) t=idx;
    num[idx]=x;
    ne[idx]=h;
    le[h]=idx;
    h=idx++;
}

void insert_tail(int x){
    if(t==0) h=idx;
    num[idx]=x;
    le[idx]=t;
    ne[t]=idx;
    t=idx++;
}

void delete_k(int k){
    if(le[k]==0) h=ne[k];
    if(ne[k]==0) t=le[k];
    ne[le[k]]=ne[k];
    le[ne[k]]=le[k];    
}

void insert_left(int k,int x){
    if(le[k]==0){
        insert_head(x);
        return;
    }
    num[idx]=x;
    ne[idx]=k;
    le[idx]=le[k];
    ne[le[k]]=idx;
    le[k]=idx++;
}

void insert_right(int k,int x){
    if(ne[k]==0){
        insert_tail(x);
        return;
    }
    num[idx]=x;
    le[idx]=k;
    ne[idx]=ne[k];
    le[ne[k]]=idx;
    ne[k]=idx++;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int m,k,x;
    string op;
    cin>>m;
    while(m--){
        cin>>op;
        if(op=="L"){
            cin>>x;
            insert_head(x);
        }
        else if(op=="R"){
            cin>>x;
            insert_tail(x);
        }
        else if(op=="D"){
            cin>>k;
            delete_k(k);
        }
        else if(op=="IL"){
            cin>>k>>x;
            insert_left(k,x);
        }
        else{
            cin>>k>>x;
            insert_right(k,x);
        }
    }
    idx=h;
    while(idx!=0){
        cout<<num[idx]<<' ';
        idx=ne[idx];
    }
    return 0;
}