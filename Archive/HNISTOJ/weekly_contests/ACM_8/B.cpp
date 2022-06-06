//前缀和+贪心？
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    double Maxdollar=100,Maxmark=0,trans=0;
    int day;
    cin>>day;
    for(int i=1;i<=day;i++){
        cin>>trans;
        if(Maxdollar/100*trans>Maxmark){
            Maxmark=Maxdollar/100*trans;
        }
        if(Maxmark/trans*100>Maxdollar){
            Maxdollar=Maxmark/trans*100;
        }
    }
    cout<<fixed<<setprecision(2)<<Maxdollar;
}