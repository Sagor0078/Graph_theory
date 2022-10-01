
//https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
const int mxN = 2e5+10;

using namespace std;
vector<ll> adj[mxN];
bool vis[mxN];
vector<vector<ll>> conected_component;
vector<ll> current_cc;

void dfs(int vertex){
	/*
	take action on vertex after entering 
	the vertex
	*/
	vis[vertex] = true;
	current_cc.pb(vertex);
	for(auto& child : adj[vertex]){
		if(vis[child]) continue;
		/*
		  take action on child before the
		  entering the child node
		*/
		dfs(child);
		/*
		take action on child 
		after exiting the child node
		*/
	}
	/*
	take action on vertex before 
	exiting the vertex 
	*/
}
int main(){
	int n,e;cin>>n>>e;
	for(int i=0;i<e;++i){
		int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
	}
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		current_cc.clear();
		dfs(i);
		conected_component.pb(current_cc);
	}
	cout<<conected_component.size()<<"\n";
	for(auto& x : conected_component){
		for(auto& y : x){
			cout<<y<<" ";
		}
	   cout<<"\n";
	}
}
