#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

double x1,y11,x2,y2,x3,y3;
double s1,s2,s3,p;
double ans,res;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>x1>>y11>>x2>>y2>>x3>>y3;
    s1=sqrt(pow(fabs(y2-y11),2)+pow(fabs(x2-x1),2));
    s2=sqrt(pow(fabs(y3-y2),2)+pow(fabs(x3-x2),2));
    s3=sqrt(pow(fabs(y11-y3),2)+pow(fabs(x1-x3),2));
    p=(s1+s2+s3)/2;

    res=sqrt(p*(p-s1)*(p-s2)*(p-s3));
    ans+=res;
    
    cin>>x1>>y11>>x2>>y2>>x3>>y3;
    s1=sqrt(pow(fabs(y2-y11),2)+pow(fabs(x2-x1),2));
    s2=sqrt(pow(fabs(y3-y2),2)+pow(fabs(x3-x2),2));
    s3=sqrt(pow(fabs(y11-y3),2)+pow(fabs(x1-x3),2));
    p=(s1+s2+s3)/2;

    res=sqrt(p*(p-s1)*(p-s2)*(p-s3));
    ans+=res;

    cout<<fixed<<setprecision(2)<<ans;
    return 0;
}