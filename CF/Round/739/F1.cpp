#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> VI;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=10;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        VI num,res;
        bool mark[10];
        memset(mark,0,sizeof mark);
        int cnt=0;

        while(n){
            int t=n%10;
            if(!mark[t]) mark[t]=1,cnt++;
            num.push_back(t);
            n/=10;
        }

        int d1=num[num.size()-1],d2=-1;


        if(k==1){
            if(cnt==1)
                for(int i:num) res.push_back(d1);
            else{
                for(int i=num.size()-2;i>=0;i--){
                    if(num[i]>d1){
                        d1++;
                        break;
                    }
                    else if(num[i]<d1)
                        break;
                }
                for(int i:num) res.push_back(d1);
            }
        }
        else if(cnt<=2){
            for(int i=num.size()-1;i>=0;i--) cout<<num[i];
            cout<<endl;
            continue;
        }
        else{
            res.push_back(d1);
            // for(int i=num.size()-2;i>=0;i--){
            //     if(num[i]!=d1){
            //         d2=num[i];
            //         break;
            //     }
            // }
            d2=num[num.size()-2];//error
            int t=max(d1,d2);
            bool flag=0;
            for(int i:num) if(i>t) flag=1;
            if(flag){
                if(d2+1==d1){
                    res.push_back(d1);
                    for(int i=num.size()-3;i>=0;i--) res.push_back(0);
                }
                else{
                    d2++;
                    res.push_back(d2);
                    for(int i=num.size()-3;i>=0;i--) res.push_back(min(d1,d2));
                }
            }
            else{
                res.push_back(d2);
                if(d1>d2) swap(d1,d2);
                for(int i=num.size()-3;i>=0;i--){
                    if(d1>=num[i]) res.push_back(d1);
                    else if(d2==num[i]) res.push_back(d2);
                    else res.push_back(d2),d2=d1;
                }
            }
        }

        for(int i:res) cout<<i;
        cout<<endl;
    }
    return 0;
}

/*

1717171 2
17893 2
98731 2
97866 2
87966 2
78911 2
97866 2
97866978 2
31666 2
9777978 2
9778999 2

999999001 2
*/