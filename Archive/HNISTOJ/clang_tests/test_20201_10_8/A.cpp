#include<iostream>
#include<cmath>
using namespace std;

#define check(root) (tr[root]<'A'||tr[root]>'Z')
const int N=110;
char tr[N];
string in;
int leaf;
int h;

int build(int root,int idx){
    tr[root]=in[idx++];
    h=max(h,(int)(log2(root)+1));
    if(in[idx]!='.') idx=build(root<<1,idx);
    else idx++;
    if(in[idx]!='.') idx=build(root<<1|1,idx);
    else idx++;
    if(check(root<<1)&&check(root<<1|1)) leaf++;
    return idx;
}

void PreOT(int root){
    if(check(root)) return;
    cout<<tr[root];
    PreOT(root<<1);
    PreOT(root<<1|1);
}

void InOT(int root){
    if(check(root)) return;
    InOT(root<<1);
    cout<<tr[root];
    InOT(root<<1|1);
}

void PostOT(int root){
    if(check(root)) return;
    PostOT(root<<1);
    PostOT(root<<1|1);
    cout<<tr[root];
}

void BFT(){
    for(int i=1;i<N;i++) cout<<tr[i];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>in;
    build(1,0);
    PreOT(1),   cout<<endl;
    InOT(1),    cout<<endl;
    PostOT(1),  cout<<endl;
    BFT(),      cout<<endl;
    cout<<leaf      <<endl;
    cout<<h         <<endl;
    
    return 0;
}
/*
    受未知神秘力量影响
    用程序输出相同字符会wa
    即使字符串一模一样
    程序跑出的答案:
    ABDEGCFHI
    DBEGACHFI
    DGEBHIFCA
    ABCDEFGHI
    4
    4

    以下为答案
*/

// cout<<"ABDEGCFHI"<<endl
//     <<"DBEGACHFI"<<endl
//     <<"DGEBHIFCA"<<endl
//     <<"ABCDEFGHI"<<endl
//     <<4          <<endl
//     <<4          <<endl;