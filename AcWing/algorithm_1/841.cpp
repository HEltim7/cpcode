#include<iostream>
using namespace std;

const int N=1e5+10;
const int P=13331;
typedef unsigned long long ull;
ull h[N],quick_P[N];

int coded(char s){
    if(s>='0'&&s<='9') return s-'0'+1;
    if(s>='a'&&s<='z') return s-'a'+1+10;
    return s-'A'+1+10+26;
}

void init(string &s){
    for(int i=0;i<s.size();i++){
        h[i+1]=h[i]*P+coded(s[i]);
    }
    quick_P[1]=P;
    for(int i=2;i<=1e5;i++) quick_P[i]=quick_P[i-1]*P;
}

void cmp(string &s,int l1,int r1,int l2,int r2){
    ull hash1=0,hash2=0;
    ull rehash=h[l1-1];
    rehash*=quick_P[r1-l1+1];
    hash1=h[r1]-rehash;
    rehash=h[l2-1];
    rehash*=quick_P[r2-l2+1];
    hash2=h[r2]-rehash;
    if(hash1==hash2) cout<<"Yes\n";
    else cout<<"No\n";
}

int main(){
    int n,m;
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    cin>>n>>m;
    string str;
    cin>>str;
    init(str);
    int l1,l2,r1,r2;
    while(m--){
        cin>>l1>>r1>>l2>>r2;
        cmp(str,l1,r1,l2,r2);
    }
    return 0;
}