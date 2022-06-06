#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef unsigned long long ull;
const int N=1e5+10;
int num[N];
vector <bool> ans[10];
string sum[10];
int howmany[10];

string mul(string a,string b){
    if(a=="0"||b=="0") return "0";
    int tmp[a.length()+b.length()+10]={0};
    string res;
    reverse(a.begin(),a.end()),reverse(b.begin(),b.end());
    for(int i=0;i<a.length();i++){
        for(int j=0;j<b.length();j++){
            int p=(a[i]-'0')*(b[j]-'0');
            int level=i+j;
            while(p){
                tmp[level]+=p%10;
                level++;
                p/=10;
            }
        }
    }
    for(int i=0;i<a.length()+b.length()+10;i++){
        int level=1,now=tmp[i]/10;
        while(now){
            tmp[i+level]+=now%10;
            now/=10;
            level++;
        }
        tmp[i]=tmp[i]%10;
    }
    for(int i=a.length()+b.length()+9;i>=0;){
        if(tmp[i]==0) i--;
        else{
            for(;i>=0;i--) res+=tmp[i]+'0';
            break;
        }
    }
    return res;
}

string make_string(int num){
    string res;
    while(num){
        res+=num%10+'0';
        num/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}

bool bigger(string a,string b){
    if(a.length()>b.length()) return 1;
    if(a.length()==b.length()){
        for(int i=0;i<a.length()-1;i++){
            if(a[i]>b[i]) return 1;
            if(i==a.length()-1) return 1;
        }
    }
    return 0;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    for(int i=1;i<=9;i++) ans[i].reserve(N);
    for(int i=1;i<=9;i++) sum[i]="0";
    int n,aim;
    cin>>n>>aim;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        int numend=num[i]%10;
        for(int j=1;j<=9;j++){
            if(sum[j]=="0"){
                if(numend==i){
                    sum[j]=num[i]+'0';
                    howmany[j]++;
                    ans[j][i]=1;
                }
                continue;
            }
            int multail=j*numend%10;
            if(multail==0) continue;
            string nowmul=mul(sum[j],make_string(num[i]));
            if(bigger(nowmul,sum[j])){
                sum[j]=nowmul;
                ans[j]=ans[multail];
            }
        }
    }
}