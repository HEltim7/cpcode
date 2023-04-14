#include<iostream>
using namespace std;

const int N=1e5+10;
const int M=10003;
int h[N],e[N],ne[N],idx;

int sha(int x){
    return (x%M+M)%M;
}

void insert(int x){
    int aim=h[sha(x)];
    if(aim==0){
        h[sha(x)]=++idx;
        e[idx]=x;
    }
    else{
        while(ne[aim]) aim=ne[aim];
        ne[aim]=++idx;
        e[idx]=x;
    }
}

void query(int x){
    int aim=h[sha(x)];
    if(aim==0){
        cout<<"No\n";
        return;
    }
    while(aim){
        if(e[aim]==x){
            cout<<"Yes\n";
            return;
        }
        aim=ne[aim];
    }
    cout<<"No\n";
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    cin>>n;
    string op;
    int x;
    while(n--){
        cin>>op>>x;
        if(op=="I") insert(x);
        else query(x);
    }
    return 0;
}