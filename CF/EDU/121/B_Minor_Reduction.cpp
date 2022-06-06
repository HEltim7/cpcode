#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        string in;
        cin>>in;
        int idx=0,val=0;
        bool res=0;
        for(int i=in.size()-2;i>=0;i--){
            int cur=in[i]-'0'+in[i+1]-'0';
            if(cur>=10) {
                for(int j=0;j<i;j++) cout<<in[j];
                cout<<cur;
                for(int j=i+2;j<in.size();j++) cout<<in[j];
                cout<<endl;
                res=1;
                break;
            }
        }
        if(!res){
            int val=in[0]-'0'+in[1]-'0';
            cout<<val;
            for(int i=2;i<in.size();i++) cout<<in[i];
            cout<<endl;
        }
    }
    return 0;
}