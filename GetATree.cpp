// https://www.eolymp.com/en/problems/978
#include<bits/stdc++.h>
using namespace std;
#define SIZE 100

bool adj[SIZE+1][SIZE+1], vis[SIZE+1];
int n,m,x,y;

inline void dfs(int X)
{
	vis[X] = true;
	for (int i = 0; i<n+1; i++)
		if (adj[X][i])
			if (!vis[i])
			{
				cout << X << " " << i <<"\n";
				dfs(i);
			}
}

int main()
{
	cin>>n>>m;
	for (int i = 0;i<m;i++)
	{
		cin >> x >> y;
		adj[x][y] = adj[y][x] = true;
	}
	dfs(1);
}