#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
int getnum[1<<7];
vector<int> num[10];
vector<int> even,odd;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    getnum['B']=1;
    getnum['E']=2;
    getnum['S']=3;
    getnum['I']=4;
    getnum['G']=5;
    getnum['O']=6;
    getnum['M']=7;
    //一个数加上偶数后奇偶性不变
    vector<string> arr;
    arr.push_back("BI");
    arr.push_back("GOES");
    arr.push_back("M");

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;
        int a,b;
        cin>>c>>b;
        a=getnum[c];
        num[a].push_back(abs(b%2));
    }
    for(auto s:arr){
        int iseven=0,isodd=0;
        for(auto c:s){
            if(c=='B'||c=='G'||c=='M'){
                for(auto x:num[getnum[c]])
                    if(x) isodd++;
                    else iseven++;
                continue;
            }
            int bakeven=0,bakodd=0;
            for(auto x:num[getnum[c]]){
                if(x) bakeven+=isodd,bakodd+=iseven; //当前是奇数
                else bakeven+=iseven,bakodd+=isodd;  //当前是偶数
            }
            iseven=bakeven;
            isodd=bakodd;
        }
        even.push_back(iseven);
        odd.push_back(isodd);
    }
    int ans=0;
    for(int i=0;i<=6;i++){
        int tmp=1;
        for(int j=0;j<=2;j++) 
            if((1<<j)&i) tmp*=odd[j];
            else tmp*=even[j];
        ans+=tmp;
    }
    cout<<ans;
    return 0;
}