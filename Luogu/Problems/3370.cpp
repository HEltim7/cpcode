#include<iostream>
#include<cmath>
using namespace std;
typedef unsigned long long ull;
const int P=131;
const int Q=1e6+3;
const int N=1e4+10;
int h[Q+1];
int sum;
struct node
{
    string str;
    int loc;
    int nex;
}str[N];

ull hashh(string in){
    ull ans=0;
    int head=-1;
    while(++head<in.length()){
        ans=(ans+in[head]*(ull)pow(P,head))%Q;
    }
    return ans;
}

void push(node in){
    int tmp=hashh(in.str);
    if(h[tmp]==0){
        h[tmp]=in.loc;
        sum++;
    }
    else{
        int nexti=h[tmp];
        while(nexti&&str[nexti].str!=in.str){
            nexti=str[nexti].nex;
        }
        if(nexti==0){
            sum++;
            in.nex=h[tmp];
            h[tmp]=in.loc;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str[i].str;
        str[i].loc=i;
        push(str[i]);
    }
    cout<<sum;
    return 0;
}