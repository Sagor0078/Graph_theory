
// https://www.eolymp.com/en/problems/4001
#include<bits/stdc++.h>
using namespace std;
int n,x,y,c = 0;
char ch[101][101];

void dfs(int x,int y){
	if(ch[x][y] == '*' || x+1 == n || y+1 == n || x-1 == -1 || y-1 == -1) return;
	c++;
	ch[x][y] = '*';
	dfs(x,y-1);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x+1,y);

}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin>>ch[i][j];
    	}
    }
    cin>>x>>y;
    dfs(x-1,y-1);
    cout<<c<<"\n";
    return 0;
}