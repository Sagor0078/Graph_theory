// https://www.eolymp.com/en/problems/982
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int mxN = 101;

bool adj[mxN][mxN];
bool vis[mxN];
int n,m,a,b,sum = 0;

void dfs(int src){
	vis[src] = true;
	sum++;
	for(int i=0;i<n;++i){
		if(adj[src][i]){
			if(!vis[i]){
				dfs(i);
			}
		}
	}
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;++i){
       cin>>a>>b;a--,b--;
       adj[a][b] = adj[b][a] = true;
    }
    dfs(0);
    if(sum == n){
    	cout<<"YES\n";
    }else{
    	cout<<"NO\n";
    }
}