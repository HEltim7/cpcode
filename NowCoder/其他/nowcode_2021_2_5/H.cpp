#include<bits/stdc++.h>
using namespace std;
const long L=2e6;
int main(){
    string aim,ans;
    cin>>aim;
    long len=aim.length();
    if(len<L){
        for(int i=0;i<=len-1;i++){
            if(aim[i]>='k'&&aim[i]<='s'||aim[i]>='u'&&aim[i]<='z'){
                for(int j=0;j<=i-1;j++){
                    ans+=aim[j];
                }
                ans+=(aim[i]-'a'+1)/10+'a'-1;
                ans+=(aim[i]-'a'+1)%10+'a'-1;
                for(int j=i+1;j<=len-1;j++){
                    ans+=aim[j];
                }
                cout<<ans;
                return 0;
            }
            else if(aim[i]=='a'&&aim[i+1]>='a'&&aim[i+1]<='i'||aim[i]=='b'&&aim[i+1]>='a'&&aim[i+1]<='f'){
                for(int j=0;j<=i-1;j++){
                    ans+=aim[j];
                }
                ans+=((aim[i]-'a'+1)*10+(aim[i+1]-'a'+1))+'a'-1;
                for(int j=i+2;j<=len-1;j++){
                    ans+=aim[j];
                }
                cout<<ans;
                return 0;
            }
        }
    }
    //这个else根本没必要
    else{
        for(int i=0;i<=len-1;i++){
            if(aim[i]=='a'&&aim[i+1]>='a'&&aim[i+1]<='i'||aim[i]=='b'&&aim[i+1]>='a'&&aim[i+1]<='f'){
                for(int j=0;j<=i-1;j++){
                    ans+=aim[j];
                }
                ans+=((aim[i]-'a'+1)*10+(aim[i+1]-'a'+1))+'a'-1;
                for(int j=i+2;j<=len-1;j++){
                    ans+=aim[j];
                }
                cout<<ans;
                return 0;
            }
            else if((aim[i]=='a'||aim[i]=='b')&&aim[i+1]!='j'&&aim[i+1]!='t'&&(i+1)<=len-1){
                for(int j=0;j<=i-1;j++){
                    ans+=aim[j];
                }
                ans+=((aim[i]-'a'+1)*10+(aim[i+1]-'a'+1)/10)+'a'-1;
                ans+=(aim[i+1]-'a'+1)%10+'a'-1;
                for(int j=i+2;j<=len-1;j++){
                    ans+=aim[j];
                }
                cout<<ans;
                return 0;
            }
        }
    }
    cout<<"-1";
    return 0;
}