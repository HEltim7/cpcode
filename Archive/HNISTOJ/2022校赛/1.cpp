#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;
const int N = 1e5+10;

map<string,map<string,string>>sts;
string qname;
string qclass;
string lname[N];
int cnt1,cnt2;
string lclass[N];

int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i ++ ){
        string name,classs,grade;
        cin>>name>>classs>>grade;
        if(qname.find(name)>=qname.length()){
            qname+=name+" ";
            lname[cnt1++]=name;
        }if(qclass.find(classs)>=qclass.length()){
            qclass+=classs+" ";
            lclass[cnt2++]=classs;
        }
        sts[name][classs]=grade;
        
    }
    cout<<"Name ";
    for (int i = 0; i < cnt2-1; i ++ ){
        cout<<lclass[i]<<" ";
    }cout<<lclass[cnt2-1]<<endl;
    for (int i = 0; i < cnt1; i ++ ){
        cout<<lname[i]<<" ";
        for (int j = 0; j < cnt2; j ++ ){
            if(j==cnt2-1){
                if(sts[lname[i]][lclass[j]]=="")cout<<"0.0";
                else cout<<sts[lname[i]][lclass[j]];
            }
            else{
                if(sts[lname[i]][lclass[j]]=="")cout<<"0.0 ";
                else cout<<sts[lname[i]][lclass[j]]<<" ";
            }
        }cout<<endl;
    }
}