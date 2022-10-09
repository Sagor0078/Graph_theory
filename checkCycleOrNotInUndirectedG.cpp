//https://www.eolymp.com/en/problems/4004
#include<bits/stdc++.h>
using namespace std;
const int N = 51;
bool vis[N];
vector<vector<int>> g(N,vector<int>(N,0));
int n;

bool dfs(int src){
   vis[src] = true;
   for(int i=0;i<n;i++){
      if(g[src][i]){
         if(vis[i] == false){
            if(dfs(i)) return  true;
         }else if(vis[i] == true){
            return true;
         }
      }
   }
   vis[src] = false;
   return false;
}
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
      vis[i] = 0;
    }
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           cin>>g[i][j];
       }
    }
    for(int i=0;i<n;i++){
        if(!vis[i] && dfs(i)){
          cout<<"1\n";return 0;
        }
    }
    cout<<"0\n";return 0;
}