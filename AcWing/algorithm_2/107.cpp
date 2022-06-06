#include <iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N = 5e5+10;
int n;
int arr[N];
int tmp[N];

LL merge_sort(int l, int r){
    if(l == r) return 0;
    int mid = l + r >> 1;
    LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);

    int i = l, j = mid + 1, cnt = l;
    while (i <= mid && j <= r){
        if(arr[i] > arr[j]) tmp[cnt++] = arr[j++], res += mid - i + 1;
        else if(arr[i]<=arr[j]) tmp[cnt++] = arr[i++];
    }
    while (i <= mid) tmp[cnt++] = arr[i++];
    while (j <= r) tmp[cnt++] = arr[j++];
    for (int i = l; i <= r; i++) arr[i] = tmp[i];
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    while (cin>>n && n){
        for (int i = 1; i <= n; i++) cin>>arr[i];
        cout<<merge_sort(1, n)<<endl;
    }
    return 0;
}