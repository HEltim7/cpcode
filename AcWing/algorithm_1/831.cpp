/*
	HEltim7版本
	下标从1开始
	ne数组定义为模板串p到i为止，最长的与p后缀相同的非平凡前缀长度
*/
#include<iostream>
using namespace std;

#define endl '\n'
const int N=1e6+10;
int ne[N];
char s[N],p[N];

void get_next(int n){
    ne[0]=ne[1]=0;
    for(int i=2,j=0;i<=n;i++){
        //int j=ne[i-1];//等效写法，相当于用上一层ne推下一层
        while(j&&p[i]!=p[j+1]) j=ne[j];
        if(p[i]==p[j+1]) j++;
        ne[i]=j;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    cin>>m;
    for(int i=1;i<=m;i++) cin>>s[i];
    get_next(n);

    for(int i=1,j=0;i<=m;i++){
        while(j&&s[i]!=p[j+1]) j=ne[j];
        if(s[i]==p[j+1]) j++;
        if(j==n){
            cout<<i-j<<' ';
            j=ne[j];
        }
    }
    return 0;
}

/*
#include<iostream>
using namespace std;

const int N=1e4+10;
int ne[N];
string base,text;

//字符串从0开始
//kmp实际上也是一种双指针算法
void getnext(){
    //ne[0]=0
    for(int i=1,j=0;i<base.length();i++){
        if(j&&base[i]!=base[j]) j=ne[j];
        if(base[i]==base[j]) j++;
        ne[i+1]=base[i+1]==base[j]?ne[j]:j;
    }
}

int main(){
    cin>>base>>text;
    getnext();
    for(int i=0,j=0;i<=text.length();i++){
        if(j==base.length()){
            cout<<i-base.length()<<' ';
            j=ne[j];
        }
        if(j&&text[i]!=base[j]) j=ne[j];
        if(text[i]==base[j]) j++;
    }
    return 0;
}
*/