#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<vector>
#include<iostream>
#include<algorithm>
#include<random>
using namespace std;

#define endl '\n'
using LL=long long;
using ULL=unsigned long long;
const int N=5e5+10;
ULL a[N],b[N];
ULL rnd[N*2];
bool sta[N*2],stb[N*2];
char ans[N*2];

namespace io {
    const int MAXBUF = 1e6;
    char buf[MAXBUF], *pl, *pr;

    #define gc() \
    (pl == pr && (pr = (pl = buf) + fread(buf, 1, MAXBUF, stdin), pl == pr) \
    ? EOF : *pl++)

    template<typename T> T rd(T &x) {
        x = 0;
        T f = 1;
        char c = gc();
        while (!isdigit(c)) {
            if (c == '-') f = -1;
            c = gc();
        }
        while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
        return x = x * f;
    }

    template<typename... T> void reads_impl(T&... x) { (rd(x),...); }

    #define read(x) io::rd(x)
    #define reads(...) io::reads_impl(__VA_ARGS__)
}

int main() {
    int n=read(n);
    random_device rdd;
    mt19937_64 gen(rdd());
    vector<int> num;
    num.reserve(n+n);
    for(int i=1;i<=n;i++) num.push_back(read(a[i]));
    for(int i=1;i<=n;i++) num.push_back(read(b[i]));

    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=n;i++) {
        a[i]=lower_bound(num.begin(),num.end(),a[i])-num.begin()+1;
        b[i]=lower_bound(num.begin(),num.end(),b[i])-num.begin()+1;
    }
    
    for(int i=1;i<=num.size();i++) rnd[i]=gen();
    for(int i=1;i<=n;i++) 
        if(!sta[a[i]]) sta[a[i]]=1,a[i]=a[i-1]^rnd[a[i]];
        else a[i]=a[i-1];
    for(int i=1;i<=n;i++) 
        if(!stb[b[i]]) stb[b[i]]=1,b[i]=b[i-1]^rnd[b[i]];
        else b[i]=b[i-1];

    int m=read(m);
    int idx=0;
    while(m--) {
        int i=read(i),j=read(j);
        ans[idx++]=a[i]==b[j]?'Y':'N';
        ans[idx++]='\n';
    }
    fwrite(ans, 1, idx, stdout);
    return 0;
}