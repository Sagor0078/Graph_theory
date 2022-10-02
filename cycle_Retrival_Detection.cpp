#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define pp pop_back

using namespace std;
const int mxN = 2e5+10;
ll n,m,p[mxN];
vector<ll> adj[mxN],ans;
bool vis[mxN];

void dfs(int u,int pu = -1){
	p[u] = pu;
	vis[u] = 1;
	for(auto v : adj[u]){
		if(v == pu) continue;
		if(vis[v]){
			int u2 = u;
			while(u^v){
				ans.pb(u);
				u = p[u];
			}
			ans.pb(v);
			ans.pb(u2);
			cout<<ans.size()<<"\n";
			for(auto& x : ans){
				cout<<x<<" ";
			}
			exit(0);
		}else{
			dfs(v,u);
		}
	}
}

int main(){
    cin>>n>>m;
    for(int i=0,a,b;i<m;i++){
    	cin>>a>>b;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    for(int i=0;i<n;++i){
    	if(!vis[i]){
    		dfs(i);
    	}
    }
    cout<<"IMPOSSIBLE";
    return 0;
}