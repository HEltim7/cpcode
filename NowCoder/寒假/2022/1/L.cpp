#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str;
        cin>>str;
        int row=0,col=0;
        double res=0;
        for(auto x:str){
            if(x=='U') row++;
            else if(x=='R') col++;
            else if(x=='L') col--;
            else row--;
            res=max(res,sqrt(row*row+col*col));
        }
        cout<<fixed<<setprecision(10)<<res<<endl;
    }
    return 0;
}