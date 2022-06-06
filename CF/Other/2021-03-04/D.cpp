#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef unsigned long long ull;
const int N=1e3+10;
string num[N];
// vector <bool> matrix[10];
bool matrixx[10][N];
int n,aim;
string ans[10];
string tmpans[10];
int cnt[10];

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

bool cmp(string a,string b){
    if(a.length()>b.length()) return 1;
    if(a.length()==b.length()){
        for(int i=0;i<=a.length()-1;i++){
            if(a[i]>b[i]) return 1;
        }
    }
    return 0;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>n>>aim;
    // for(int i=1;i<=9;i++) matrix[i].reserve(N);
    int tail,inend;
    string in;
    for(int i=1;i<=n;i++){
        cin>>in;
        num[i]=in;
        inend=in[in.length()-1]-'0';
        for(int k=1;k<=9;k++){
            tmpans[k]=ans[k];
        }
        for(int j=1;j<=9;j++){
            if(tmpans[j].empty()){
                if(inend==j){
                    ans[j]=in;
                    cnt[j]++;
                    // matrix[j][i]=1;
                    matrixx[j][i]=1;
                }
                continue;
            }
            tail=j*inend%10;
            if(tail==0) continue;
            if(inend==1){
                ans[tail]=mul(tmpans[j],in);
                // matrix[tail][i]=1;
                matrixx[tail][i]=1;
                cnt[tail]++;
            }
            else{
                string tmp=mul(tmpans[j],in);
                if(cmp(tmp,ans[tail])){
                    ans[tail]=tmp;
                    // matrix[tail]=matrix[j];
                    // matrix[tail][i]=1;
                    for(int i=1;i<=n;i++){
                        matrixx[tail][i]=matrixx[j][i];
                    }
                    matrixx[tail][i]=1;
                    cnt[tail]=cnt[j]+1;
                }
            }
        }
    }
    cout<<cnt[aim]<<'\n';
    for(int i=1;i<=n;i++){
        if(matrixx[aim][i]){
            cout<<num[i]<<' ';
        }
    }
    return 0;
}