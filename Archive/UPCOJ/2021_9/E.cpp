#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;

int num[1000];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    string s[7];
    s[1]="BFPV";
    s[2]="CGJKQSXZ";
    s[3]="DT";
    s[4]="L";
    s[5]="MN";
    s[6]="R";
    for(int i=1;i<=6;i++){
        for(int j=0;j<s[i].size();j++) num[s[i][j]]=i;
    }

    string in;
    while(cin>>in){
        char last='-';
        int lastn=-1;
        for(int i=0;i<in.size();i++){
            if(last==in[i]) continue;
            last=in[i];
            if(lastn==num[last]) continue;
            lastn=num[last];
            if(num[last]) cout<<num[last];
        }
        cout<<'\n';
    }

    return 0;
}