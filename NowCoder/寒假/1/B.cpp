#include<iostream>
#include<cmath>
using namespace std;

#define endl '\n'
const int N=2e5+10;

int len;
struct BLOCK{
    int l,r;
    int s[3];
} block[N];
char str[N];

inline int get(int x){
    return x/len;
}

inline void mv(int &l,int &s){
    if(str[l]=='W') s++;
    else if(str[l]=='L'&&s%3) s--;
    l++;
}

void init(int n){
    for(int i=1;i<=n;i+=i==1?len-1:len){
        block[get(i)].l=i;
        if(i==1) block[get(i)].r=min(len-1,n);
        else block[get(i)].r=min(i+len-1,n);
        for(int j=0;j<=2;j++){
            int score=j;
            int idx=i;
            do
            {
                mv(idx,score);
            } while (get(idx)==get(idx-1)&&idx<=n);
            block[get(idx-1)].s[j]=score-j;
        }
    }
}

int main() {
    freopen64("in.txt","r",stdin);
    freopen64("out.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    len=sqrt(n)+1;
    for(int i=1;i<=n;i++) cin>>str[i];
    init(n);

    while(m--){
        int l,r,s;
        cin>>l>>r>>s;
        if(get(r)-get(l)<=1){
            while(l<=r) mv(l,s);
        }
        else{
            while(get(l)==get(l-1)) mv(l,s);
            while(get(l)<get(r)){
                s+=block[get(l)].s[s%3];
                l=block[get(l)].r+1;
            }
            while(l<=r) mv(l,s);
        }
        cout<<s<<endl;
    }
    return 0;
}