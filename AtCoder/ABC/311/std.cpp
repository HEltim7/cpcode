#include<bits/stdc++.h>

using namespace std;

int sum2d(int fx,int fy,int tx,int ty,vector<vector<int>> &s){
  if(fx>tx || fy>ty){return 0;}
  if(fx==0 && fy==0){return s[tx][ty];}
  else if(fx==0){
    return s[tx][ty]-s[tx][fy-1];
  }
  else if(fy==0){
    return s[tx][ty]-s[fx-1][ty];
  }
  else{
    return s[tx][ty]-s[tx][fy-1]-s[fx-1][ty]+s[fx-1][fy-1];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<vector<int>> a(n,vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> a[i][j];
    }
  }
  vector<vector<int>> s=a;
  for(int i=1;i<n;i++){
    for(int j=0;j<m;j++){s[i][j]+=s[i-1][j];}
  }
  for(int i=0;i<n;i++){
    for(int j=1;j<m;j++){s[i][j]+=s[i][j-1];}
  }

  long long res=0;
  for(int mi=1;mi<=300;mi++){
    vector<pair<int,int>> vp(m);
    for(int i=0;i<m;i++){
      vp[i].first=0;
      vp[i].second=i;
    }

    for(int i=0;i<n;i++){
      vector<pair<int,int>> top,bot;
      for(auto &nx : vp){
        if(a[i][nx.second]>=mi){
          top.push_back({nx.first+1,nx.second});
        }
        else{
          bot.push_back({0,nx.second});
        }
      }
      vp.clear();
      for(auto &nx : top){vp.push_back(nx);}
      for(auto &nx : bot){vp.push_back(nx);}

      vector<int> lef(m),rig(m);
      for(int j=0;j<m;j++){
        lef[j]=j-1;
        rig[j]=j+1;
      }

      for(auto &nx : vp){
        int cl=lef[nx.second];
        int cr=rig[nx.second];
        if(cl>=0){rig[cl]=cr;}
        if(cr<m){lef[cr]=cl;}
        long long cf=sum2d(i-nx.first+1,cl+1,i,cr-1,s);
        cf*=mi;
        res=max(res,cf);
      }
    }
  }
  cout << res << "\n";
  return 0;
}
