#include<iostream>
using namespace std;

const int N = 1e5+10;
int num[N];
typedef long long ll;
ll ans;

void merge_sort(int l,int r,int num[]){
    if(l>=r) return;
    int mid=l+r>>1;
    int tmp[N],cnt=l,i=l,j=mid+1;
    merge_sort(l,mid,num),merge_sort(mid+1,r,num);
    while(i<=mid&&j<=r){
        if(num[i]>num[j]){
            ans+=mid-i+1;
            tmp[cnt++]=num[j++];
        }
        else tmp[cnt++]=num[i++];
    }
    while(i<=mid) tmp[cnt++]=num[i++];
    while(j<=r) tmp[cnt++]=num[j++];
    for(int i=l;i<=r;i++) num[i]=tmp[i];
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
    merge_sort(1,n,num);
    cout<<ans;
    return 0;
}