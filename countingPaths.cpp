//https://practice.geeksforgeeks.org/problems/possible-paths-between-2-vertices-1587115620/1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int mxN = 100;
bool vis[mxN];
vector<int> adj[mxN];
int src,dst,v,e,m,cnt_path = 0;

int dfs(int src,int dst){
     // int cnt_path = 0;
     vis[src] = true;
     if(src == dst){
     	cnt_path++;
     	// cout<<cnt_path<<"\n";
     	// return cnt_path;
     }else{
     	for(auto& x : adj[src]){
     		if(!vis[x]){
     			dfs(x,dst);
     		}
     	}
     }
     vis[src] = false;
     return cnt_path;
}
int main(){
    cin>>v>>e>>src>>dst;
    for(int i=0;i<e;++i){
    	int a,b;cin>>a>>b;
    	adj[a].pb(b);
    }
    cout<<dfs(src,dst)<<"\n";
    // dfs(src,dst);
}