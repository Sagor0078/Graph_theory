
//https://atcoder.jp/contests/abc266/tasks/abc266_f
#include<bits/stdc++.h>
using namespace std;
/* ???
   step 1 :Understanding the problem
   step 2: Using past Problems
   step 3 : Using known ideas/Algorithms
   step 4:{Observations} , {Reductions} , {Random ideas} , {Answer bound} ,{simpler problems} .>__<.
*/
const int mx = 200005;
vector<int> a[mx];
int64_t vis[mx],cycle[mx],partofcycle[mx];
int x,y,q;

bool dfs(int i,int p = -1){
    vis[i] = 1;
    for(auto j : a[i]){
        if(vis[j] == 0){
            partofcycle[j] = i;
            if(dfs(j,i)) return true;
        }else if(j!=p){
            int c = i;
            int t1 = 0;
            while(c!=j){
                cycle[c] = 1;
                c = partofcycle[c];
            }
            cycle[c] = 1;
            return true;
        }
    }
    return false;
}
void dfs2(int i,int c){
    vis[i] = 1;
    for(auto j : a[i]){
        if(vis[j] == 0 && cycle[j]!=1){
            cycle[j] = c;
            dfs2(j,c);
        }
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=0;i<=n;i++){
        vis[i] = cycle[i] = partofcycle[i] = 0;
    }
    dfs(1);
    for(int i=0;i<=n;++i){
        vis[i] = 0;
    }
    for(int i=1;i<=n;++i){
        if(cycle[i] == 1){
            dfs2(i,i+1);
        }
    }
    cin>>q;
    while(q--){
        cin>>x>>y;
        if(cycle[x] == 1 && cycle[y] == 1){
            cout<<"No\n";
        }else if(cycle[x]!=1 && cycle[y]!=1){
            if(cycle[x] == cycle[y]) cout<<"Yes\n";
            else cout<<"No\n";
        }else if(cycle[x] == 1){
            if(cycle[y] == x+1) cout<<"Yes\n";
            else cout<<"No\n";
        }else{
            if(cycle[x] == y+1) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--) {solve();}
}
