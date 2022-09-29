//https://atcoder.jp/contests/abc270/tasks/abc270_c
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back

const int mxN = 2e5+10;
vector<ll> adj[mxN];
bool visited[mxN];
vector<ll> st;
void dfs(int x,int y){
    st.pb(x);
    if(x == y){
    	for(int i=0;i<st.size();i++){
    		cout<<st[i]<<" ";
    	}
    	cout<<"\n";
    	return;
    }
    visited[x] = true;
    if(!adj[x].empty()){
    	for(int j=0;j<adj[x].size();j++){
    	    if(visited[adj[x][j]] == false){
    	    	dfs(adj[x][j],y);
    	    }	
    	}
    }
    st.pop_back();
}
int main(){
	int N,u,v;cin>>N>>u>>v;
	N--;
	for(int i=0;i<N;++i){
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(u,v);
	return 0;
}
