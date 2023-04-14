#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> VI;

const int N=40;
int cmb[N][N];
int x,y,k,b;


void init(){
    for(int i=0;i<=N;i++) cmb[i][0]=1;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cmb[i][j]=cmb[i-1][j]+cmb[i-1][j-1];
}

int dp(int n){
    if(n==0) return 0;
    VI num;
    while(n) num.push_back(n%b),n/=b;
    int last=0,res=0;

    for(int i=num.size()-1;~i&&last<k;i--){
        int x=num[i];
        if(x>1){
            res+=cmb[i+1][k-last];
            break;
        }
        else if(x==1){
            res+=cmb[i][k-last];
            last++;
        }
    }
    if(last==k) res++;
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    init();
    cin>>x>>y>>k>>b;
    cout<<dp(y)-dp(x-1);
    return 0;
}