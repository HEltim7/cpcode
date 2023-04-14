#include<iostream>
using namespace std;

int main(){
    string base;
    int p1,p2,p3;
    cin>>p1>>p2>>p3;
    cin>>base;
    if(p1==1){
        if(p3==1){
            for(int i=0;i<=base.length()-1;i++){
                if(base[i]!='-') cout<<base[i];
                else{
                    if(base[i-1]==base[i+1]-1) continue;
                    else if(base[i-1]>=base[i+1]||base[i-1]<='9'&&base[i+1]>='a'||i==0||i==base.length()-1||base[i-1]=='-'||base[i+1]=='-') cout<<'-';
                    else{
                        for(char first=base[i-1]+1;first<base[i+1];first++){
                            for(int k=1;k<=p2;k++) cout<<first;
                        }
                    }
                }
            }
        }
        else{
            for(int i=0;i<=base.length()-1;i++){
                if(base[i]!='-') cout<<base[i];
                else{
                    if(base[i-1]==base[i+1]-1) continue;
                    else if(base[i-1]>=base[i+1]||base[i-1]<='9'&&base[i+1]>='a'||i==0||i==base.length()-1||base[i-1]=='-'||base[i+1]=='-') cout<<'-';
                    else{
                        for(char first=base[i+1]-1;first>base[i-1];first--){
                            for(int k=1;k<=p2;k++) cout<<first;
                        }
                    }
                }
            }
        }
    }
    else if(p1==2){
        if(p3==1){
            for(int i=0;i<=base.length()-1;i++){
                if(base[i]!='-') cout<<base[i];
                else{
                    if(base[i-1]==base[i+1]-1) continue;
                    else if(base[i-1]>=base[i+1]||base[i-1]<='9'&&base[i+1]>='a'||i==0||i==base.length()-1||base[i-1]=='-'||base[i+1]=='-') cout<<'-';
                    else{
                        if(base[i-1]<='9'&&base[i-1]>='0')
                            for(char first=base[i-1]+1;first<base[i+1];first++){
                                for(int k=1;k<=p2;k++) cout<<first;
                            }
                        else{
                            for(char first=base[i-1]+1-'a'+'A';first<base[i+1]-'a'+'A';first++){
                                for(int k=1;k<=p2;k++) cout<<first;
                            }
                        }
                    }
                }
            }
        }
        else{
            for(int i=0;i<=base.length()-1;i++){
                if(base[i]!='-') cout<<base[i];
                else{
                    if(base[i-1]==base[i+1]-1) continue;
                    else if(base[i-1]>=base[i+1]||base[i-1]<='9'&&base[i+1]>='a'||i==0||i==base.length()-1||base[i-1]=='-'||base[i+1]=='-') cout<<'-';
                    else{
                        if(base[i-1]<='9'&&base[i-1]>='0')
                            for(char first=base[i+1]-1;first>base[i-1];first--){
                                for(int k=1;k<=p2;k++) cout<<first;
                            }
                        else{
                            for(char first=base[i+1]-1-'a'+'A';first>base[i-1]-'a'+'A';first--){
                                for(int k=1;k<=p2;k++) cout<<first;
                            }
                        }
                    }
                }
            }
        }
    }
    else{
        for(int i=0;i<=base.length()-1;i++){
            if(base[i]!='-') cout<<base[i];
            else{
                if(base[i-1]==base[i+1]-1) continue;
                else if(base[i-1]>=base[i+1]||base[i-1]<='9'&&base[i+1]>='a'||i==0||i==base.length()-1||base[i-1]=='-'||base[i+1]=='-') cout<<'-';
                else{
                    for(char first=base[i-1]+1;first<base[i+1];first++){
                        for(int k=1;k<=p2;k++) cout<<'*';
                    }
                }
            }
        }
    }
    return 0;
}