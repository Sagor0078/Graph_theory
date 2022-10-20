#include<bits/stdc++.h>
using namespace std;
string a,b;
int dx[9] = {1,1,-1,-1,2,-2,2,-2};
int dy[9] = {2,-2,2,-2,1,1,-1,-1};

bool isvalid(int i,int j,vector<vector<bool>>& vis){
	 if(i>=1 && i<9 && j>=1 && j<9 && vis[i][j] == false){
	 	return true;
	 }
	 return false;
}
int MinKnightMoves(int kx,int ky,int tx,int ty){
	if(tx == kx && ty == ky) return 0;
	vector<vector<bool>> vis(9,vector<bool>(9,false));
	queue<pair<int,int>> q;
	q.push({kx,ky});
	vis[kx][ky] = true;
	int ans = 0;
	while(!q.empty()){
		int sz = q.size();
		ans++;
		while(sz!=0){
			pair<int,int> p = q.front();
			q.pop();
			int xx = p.first;
			int yy = p.second;
			for(int i = 1;i<=8;i++){
				int nx = xx + dx[i];
				int ny = yy + dy[i];
				// cout<<nx<<" "<<ny<<"\n";
				if(nx == tx && ny == ty) return ans;
				if(isvalid(nx,ny,vis)){
					vis[nx][ny] = true;
					q.push({nx,ny});
				}
			}
			sz--;
		}
	}
	return ans;
}

int main(){
    while(cin>>a>>b){
    	int kx = a[0]-97+1, ky = a[1]-48;
    	int tx = b[0]-97+1, ty = b[1]-48;
    	// cout<<kx<<" "<<ky<<"\n";
    	// cout<<tx<<" "<<ty<<"\n";
    	cout<<"To get from "<<a<<" to "<<b<<" takes "<<MinKnightMoves(kx,ky,tx,ty)<<" knight moves."<<"\n";
    }
}