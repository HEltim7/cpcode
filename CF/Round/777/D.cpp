#include<iostream>
#include<vector>
#include<set>
using namespace std;

#define endl '\n'
typedef long long LL;

bool check(int x){
    for(int i=2;i<=x/i;i++) if(x%i==0) return 0;
    return 1;
}

bool beautiful(LL x,LL d){
    return x%(d*d)>0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int a=0,x,d;
        cin>>x>>d;
        LL d2=1LL*d*d;
        if(x%d2){
            cout<<"NO"<<endl;
            continue;
        }
        while(x%d==0) x/=d,a++;
        if(a==2){
            if(check(x)) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        else if(a==3){
            if(check(x)){
                if(check(d)) cout<<"NO"<<endl;
                else{
                    bool ans=0;
                    for(int i=2;i<=d/i&&!ans;i++){
                        if(d%i) continue;
                        if(beautiful(1LL*d*i,d)&&beautiful(1LL*d*(d/i)*x,d)) ans=1;
                        if(beautiful(1LL*d*i*x,d)&&beautiful(1LL*d*(d/i),d)) ans=1;
                    }
                    cout<<(ans?"YES":"NO")<<endl;
                }
            }
            else cout<<"YES"<<endl;
        }
        else{
            if(check(d)){
                if(check(x)) cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
            }
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}

/*

beautiful: 不是d*d 的整数倍
suitable: 
- beautiful -> NO
- x=d^a k

若a==2 :
    若k为质数 -> NO
    若k为合数 -> YES

若a==3 :
    若k为合数 -> YES
    若k为质数 :
        若d为质数 -> NO
        若d为合数 -> BF

若a！=3 :
    若d为质数 :
        若k为质数 -> NO
        若k为合数 -> YES
            证明：一定存在两种序列 d,d,...,kd 和 d,d,...,ad,bd(a*b=k,a!=1,b!=1)
    若d为合数 -> YES
    
*/