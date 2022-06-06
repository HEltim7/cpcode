#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

typedef long long ll;
const int N=1e3+10;
int prob[4][N];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    string in;
    cin>>t;
    getline(cin,in);
    while(t--){
        memset(prob,0,sizeof prob);
        for(int k=1;k<=3;k++){
            int cnt=0;
            getline(cin,in);
            for(int i=0;i<in.size();i++){
                if(in[i]==' ') continue;
                int num=0;
                do num=num*10+in[i]-'0'; while(in[i+1]<='9'&&in[++i]>='0');
                prob[k][++cnt]=num;
            }
        }

    }
    return 0;
}