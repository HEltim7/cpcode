//能指定生成个数（不能比范围大），指定上下限（不能负），附带去重和排序功能
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
long maxx,minn,num,tail,tmp;
bool ans[1000000];

// 线性生成+选排
// long ans[1000000];
// void gen(long num,long maxx,long minn){
//     srand((unsigned)time(NULL));
//     for(int i=1;i<=num;i++){
//         ans[++tail]=rand()%(maxx-minn)+1+minn;
//         for(int j=1;j<tail;j++){
//             if(ans[j]==ans[tail]){
//                 tail--;
//                 i--;
//                 break;
//             }
//         }
//     }
//     return;
// }

// void sort(){
//     while(tail>1){
//         long maxx=-10000000,j=tail,t;
//         for(int i=1;i<=tail;i++){
//             if(ans[i]>maxx){
//                 maxx=ans[i];
//                 j=i;
//             }
//         }
//         t=ans[tail];
//         ans[tail--]=ans[j];
//         ans[j]=t;
//     }
//     return;
// }

//桶生成,自带排序去重
void Gen(long num,long maxx,long minn){
    srand((unsigned)time(NULL));
    for(int i=1;i<=num;i++){
        tmp=rand()%(maxx-minn+1)+minn;
        if(ans[tmp]!=1){
            ans[tmp]=1;
        }
        else{
            i--;
        }
    }
    return;
}



int main()
{
    srand((unsigned)time(NULL));
    printf("%s\n","please enter the count you wanna generate:");
    scanf("%ld",&num);
    printf("%s\n","please enter the range-->upper limit");
    scanf("%ld",&maxx);
    printf("%s\n","please enter the range-->lower limit");
    scanf("%ld",&minn);
    if(maxx-minn+1<num||maxx<0||minn<0||num<=0){
        printf("%s\n","[error]illegal input");
        return 0;
    }
    printf("%s\n","The result is:");
    Gen(num,maxx,minn);
    int j=0;
    for(int i=0;i<=maxx;i++){
        if(ans[i]){
            printf("[%ld]%ld\n",++j,i);
        }
    }
    return 0;
    // gen(num,maxx,minn);
    // sort();
    // for(int i=1;i<=num;i++){
    //     printf("%ld\n",ans[i]);
    // }
    // return 0;
}