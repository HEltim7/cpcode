#include<iostream>
using namespace std;
char a[110],b[110];
int maxx,minn;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        if(a[i]==b[i]) maxx+=2;
        else maxx++;
    }
    cout<<maxx<<' '<<minn;
    return 0;
}