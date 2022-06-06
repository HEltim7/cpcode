#include<iostream>
using namespace std;
const int P=2000003;
#define hash(x) (x%P+P)%P
const int N=2e5+10;
struct hash_node
{
    int data;
    int same;
}h[2000000];
int num[N];
long long sum;

void push(int in){
    int tmp=hash(in);
    while(h[tmp].same&&h[tmp].data!=in) tmp++;
    h[tmp].data=in;
    h[tmp].same++;
}

void check(int aim){
    int tmp=hash(aim);
    while(h[tmp].same&&h[tmp].data!=aim) tmp++;
    sum+=h[tmp].same;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n,c;
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        push(num[i]);
    }
    for(int i=1;i<=n;i++) check(num[i]-c);
    cout<<sum;
    return 0;
}