#include<iostream>
#include<string>
using namespace std;

int main(){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(int i=0;i<a.length();i++){
        for (int j=0; j<b.length(); j++)
        {
            if(a[i]==b[j]){
                cout<<"yes";
                return 0;
            }
        }
    }
    cout<<"no";
    return 0;
}