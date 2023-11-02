#include <cmath>
#include<iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll=long long;


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> cnt(31);
        int up=30;
        for(int i=0; i<n; ++i) {
            int x;
            cin>>x;
            for(int j=0; j<=30; ++j)
                cnt[j] += x>>j&1;
        }
        
        int ans=0;
        while(true) {
            while(up>=0 and !cnt[up]) up--;
            if(up==-1) break;

            ans++;
            for(int i=0; i<=up; ++i) {
                while(up>=0 and !cnt[up]) up--;
                if(i>up) break;
                if(cnt[i]) {
                    cnt[i]--;
                }else {
                    for(int j=i+1; j<=up; ++j) {
                        if(cnt[j]) {
                            cnt[i]++;
                            cnt[j]--;
                            i=j-1;
                            break;
                        }
                    }
                }
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}