#include<iostream>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int begin,cnt=0;
    while(cin>>begin&&begin>=0){
        cout<<"Case "<<++cnt<<":"<<'\n';
        int probs[14]={0};
        int requ[14]={0};
        int lefts=0;
        probs[1]=begin;
        for(int i=1;i<=12;i++) cin>>probs[i+1];
        for(int i=1;i<=12;i++) cin>>requ[i];
        for(int i=1;i<=12;i++){
            lefts+=probs[i];
            if(lefts<requ[i]) cout<<"No problem. :("<<'\n';
            else {
                cout<<"No problem! :D"<<'\n';
                lefts-=requ[i];
            }
        }
    }
    return 0;
}