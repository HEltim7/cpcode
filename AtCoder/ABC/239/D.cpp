#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

inline bool check(int x){
    for(int i=2;i<=x/i;i++)
        if(x%i==0) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    for(int i=a;i<=b;i++){
        bool res=1;
        for(int j=c;j<=d;j++)
            if(check(i+j)) res=0;
        if(res){
            cout<<"Takahashi";
            return 0;
        }
    }
    cout<<"Aoki";
    return 0;
}