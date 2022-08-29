#include<bits/stdc++.h>
#define max(p,q)((p)>(q)?(p):(q))
using namespace std;
int main(){
	int n;
	cin>>n;
	double ans = 3.5; // for (n = 1) 1/6+2/6+3/6+4/6+5/6+6/6
    for(int i=1;i<n;++i){
    	double ans2 = 0;
    	for(int d=1;d<=6;d++) ans2+=max(ans,d)/6;
    		// fraction value er jonno c++ er max function kaj kore nah**
    	ans = ans2;
    }
    cout<<setprecision(10)<<fixed<<ans<<"\n";
}

