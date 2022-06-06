#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n,R,r;
        cin>>n>>R>>r;
        int ans=0;
        int minn=1e9;
        int checknum=(R-2*r)*(R-2*r);//距离原点大于此数则取离原点最近的点
        vector<int> buildings;
        for(int i=1;i<=n;i++){
            int x,y;
            cin>>x>>y;
            int res=x*x+y*y;
            if(res>R*R) continue;//毒圈外

            if(res<=checknum) res=0;
            if(res<minn){
                buildings.clear();
                buildings.push_back(i);
                minn=res;
                ans=1;
            }
            else if(res==minn){
                buildings.push_back(i);
                ans++;
            }
        }
        cout<<ans<<endl;
        for(int i=0;i<ans-1;i++) cout<<buildings[i]<<' ';
        cout<<buildings[ans-1]<<endl;
    }
    return 0;   
}