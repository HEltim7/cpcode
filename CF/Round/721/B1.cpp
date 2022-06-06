#include<iostream>
using namespace std;

const int N=1e3+10;
int a[N],b[N];
void dabiao(){
    a[1]=1,b[1]=0;
    a[2]=2,b[2]=0;
    for(int i=3;i<=1000;i++){
        if(i%2==0){
            a[i]=b[i-2]+2;
            b[i]=a[i-2];
        }
        else{
            a[i]=b[i-1]+1;
            b[i]=a[i-1];
        }
    }
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    // dabiao();
    int t;
    string s;
    // for(int i=0;i<=1000;i++){
    //     int zero=i;
    //     cout<<zero<<' ';
    //     if(a[zero]>b[zero]) cout<<"BOB\n";
    //     else if(a[zero]<b[zero]) cout<<"ALICE\n";
    //     else cout<<"DRAW\n";
    // }
    cin>>t;
    while(t--){
        cin>>s>>s;
        int zero=0;
        for(int i=0;i<s.size();i++) if(s[i]=='0') zero++;
        if(zero%4==0) cout<<"DRAW\n";
        else if(zero%4==3) cout<<"ALICE\n";
        else cout<<"BOB\n";
        // if(a[zero]>b[zero]) cout<<"BOB\n";
        // else if(a[zero]<b[zero]) cout<<"ALICE\n";
        // else cout<<"DRAW\n";
    }
    return 0;
}