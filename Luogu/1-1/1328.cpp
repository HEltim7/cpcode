#include<iostream>
using namespace std;
const int N=210;
int A[N],B[N];
int Awin,Bwin;

void check(int a,int b){
    if(a==b) return;
    switch (a){
    case 0:
        if(b==1||b==4) Bwin++;
        else Awin++;
        break;
    case 1:
        if(b==2||b==4) Bwin++;
        else Awin++;
        break;
    case 2:
        if(b==0||b==3) Bwin++;
        else Awin++;
        break;
    case 3:
        if(b==0||b==1) Bwin++;
        else Awin++;
        break;
    case 4:
        if(b==2||b==3) Bwin++;
        else Awin++;
        break;
    default:
        break;
    }
}

int main(){
    int n,na,nb;
    cin>>n>>na>>nb;
    for(int i=1;i<=na;i++) cin>>A[i];
    for(int i=1;i<=nb;i++) cin>>B[i];
    for(int i=1;i<=n;i++) check(A[(i-1)%na+1],B[(i-1)%nb+1]);
    cout<<Awin<<' '<<Bwin;
    return 0;
}