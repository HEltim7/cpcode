#include<iostream>
using namespace std;

const int N=1e5+10;
int stack[N];
int idx;

void push(int x){
    stack[++idx]=x;
}

int query(){
    return stack[idx];
}

void pop(){
    idx--;
}

bool empty(){
    return idx;
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
        else if(op=="query"){
            cout<<query()<<'\n';
        }
        else if(op=="pop"){
            pop();
        }
        else if(op=="empty"){
            if(!empty()) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}