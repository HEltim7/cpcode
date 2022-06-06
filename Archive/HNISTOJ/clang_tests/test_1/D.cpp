#include<bits/stdc++.h>
using namespace std;

int main(){
    int day,now,next,maxx=0,MAXX=0;
    cin>>day;
    cin>>now;
    for(int i=2;i<=day;i++){
        cin>>next;
        if(next>now){
            maxx++;
            MAXX=max(maxx,MAXX);
        }
        else
            maxx=0;
        now=next;
    }
    cout<<MAXX+1;
    return 0;
}