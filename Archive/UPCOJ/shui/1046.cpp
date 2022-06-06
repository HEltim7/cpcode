#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);
    string in;
    while (cin>>in){
        for(auto i:in) if(i=='6') cout<<"zan!";
        cout<<endl;
    }
    return 0;
}