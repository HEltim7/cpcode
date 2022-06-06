#include<iostream>
using namespace std;
const int N=1e6+10;
const int P=1e6+3;
#define hash(x) (x%P+P)%P
struct num_node{
    int data;
    int same=1;
    int loc;
    int nex=-1;
}num[N];
int h[N];
long long sum;

void push(num_node in){
    int tmp=hash(in.data);
    int nexti=h[tmp];
    if(nexti==0) h[tmp]=in.loc;
    else{
        while(nexti&&num[nexti].data!=in.data) nexti=num[nexti].nex;
        if(nexti==-1){
            in.nex=h[tmp];
            h[tmp]=in.loc;
        }
        else num[nexti].same++;
    }
}

void check(int aim){
    int tmp=hash(aim);
    int nexti=h[tmp];
    while(nexti&&num[nexti].data!=aim) nexti=num[nexti].nex;
    if(nexti) sum+=num[nexti].same;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n,c;
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>num[i].data;
        num[i].loc=i;
        push(num[i]);
    }
    for(int i=1;i<=n;i++) check(num[i].data-c);
    cout<<sum;
    return 0;
}