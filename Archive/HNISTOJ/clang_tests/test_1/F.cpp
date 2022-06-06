#include<bits/stdc++.h>
using namespace std;

struct data{
    string id;
    int a;
    int b;
    int c;
    int sum;
};

bool cmp(data x,data y){
    return x.sum>y.sum;
}

int main(){
    int man;
    cin>>man;
    data grade[man];
    for(int i=0;i<man;i++){
        cin>>grade[i].id>>grade[i].a>>grade[i].b>>grade[i].c;
        grade[i].sum=grade[i].a+grade[i].b+grade[i].c;
    }
    sort(grade,grade+man,cmp);
    for(int i=0;i<man;i++){
        cout<<grade[i].id<<' '<<grade[i].a<<' '<<grade[i].b<<' '<<grade[i].c<<' '<<grade[i].sum<<endl;
    }
    return 0;
}