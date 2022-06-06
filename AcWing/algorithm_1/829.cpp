#include<iostream>
using namespace std;

const int N=1e5+10;
int queue[N],h=1,t;

void push(int x){
    queue[++t]=x;
}

void pop(){
    h++;
}

bool empty(){
    return t<h;
}

int query(){
    return queue[h];
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int m,x;
    string op;
    cin>>m;
    while(m--){
        cin>>op;
        if(op=="push"){
            cin>>x;
            push(x);
        }
        else if(op=="pop"){
            pop();
        }
        else if(op=="empty"){
            if(empty()) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
            cout<<query()<<'\n';
        }
    }
    return 0;
}