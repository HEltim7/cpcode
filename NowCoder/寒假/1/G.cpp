#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define endl '\n'
typedef pair<int,int> PII;
const int N=1e5+10,INF=0x3f3f3f3f;

vector<PII> num;
int in[N];

int main() {
    // freopen64("in.txt","r",stdin);
    // freopen64("out.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        num.clear();
        int n,ans=INF;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>in[i];
        for(int i=2;i<n;i++){
            int a=in[i-1],b=in[i],c=in[i+1];
            if(a==b||b==c) continue;
            if(a<c) swap(a,c);
            if(b<c) num.push_back({-1,1}),num.push_back({(b+c+1)/2,-1});
            else if(a>b&&b>c) num.push_back({(b+c)/2+1,1}),num.push_back({(a+b+1)/2,-1});
            else num.push_back({(a+b)/2+1,1});
        }
        num.push_back({-1,0});
        sort(num.begin(),num.end());
        int sum=0;
        for(int i=0;i<num.size();i++){
            for(int j=i;j<num.size();j++){
                if(num[j].first!=num[i].first){
                    i=j-1;
                    break;
                }
                sum+=num[j].second;
            }
            ans=min(ans,sum);
        }
        
        cout<<ans<<endl;
    }
    return 0;
}

/*

10
22 75 26 45 72 81 47 29 97 2 

10
57 39 18 11 79 6 40 68 68 16 

10
11 67 67 74 91 4 35 34 65 80 

5
2 5 6 5 2 

5
2 8 3 5 2 x
*/