#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back

int n;
vector<ll> v;
int dp[100050];
int y;

ll max(ll a, ll b) {
    return a>b?a:b;
}

/*
ll answer(int i, int j, int idx, ll prince, ll suml, ll sumr) {
	// cout<<"i = "<<i<<" j = "<<j<<" idx = "<<idx<<" prince = "<<prince<<" suml = "<<suml<<" sumr = "<<sumr<<endl;
	if((suml>=prince && sumr<prince)||i==0) {
		for(y = j+1;y<n;y++,idx--) {
			sumr = sumr+v[idx];
			if(sumr>=prince && suml>=prince) {
				return (n-y)+i+1;
			} else if(sumr>=prince && suml<prince) {
				return (n-y);
			}
		}
		if(suml>=prince && sumr<prince) {
			// cout<<"dhanraj1 = "<<i+1<<endl;
			return i+1;
		} 
		else return 0;
	}
	if((suml<prince && sumr>=prince)||j==n-1) {
		for(y=i-1;y>=0;y--,idx--) {
			suml = suml+v[idx];
			if(suml>=prince && sumr>=prince) {
				return (n-j)+y+1;
			} else if(suml>=prince && sumr<prince) {
				return y+1;
			}
		}
		if(suml<prince && sumr>=prince) {
			// cout<<"amit1 = "<<(n-j)<<endl;
			return (n-j);
		}
		else return 0;
	}
	if(suml>=prince && sumr<=prince) {
		return (n-j)+i+1;
	}

	return max(answer(i,j+1,idx-1,prince,suml,sumr+v[idx]),answer(i-1,j,idx-1,prince,suml+v[idx],sumr));

}*/


int main() {

	int t;
	cin>>t;
	while(t--) {
		ll p;
		cin>>n>>p;

		ll x;
		for(int i=0;i<n;i++) {
			cin>>x;
			v.pb(x);
		}

		sort(v.begin(),v.end());

		ll ans[n];
		int i=n-1;
		ll sum=0;
		for(;i>=0;--i) {
			sum+= v[i];
			if(sum>=p) break;
		}

		if(i<0) {

		} else if(i==0){

		} else {
			sum = v[n-1];
			int j=i-1;
			for(;j>=0;j--) {
				if(sum<p) {
					sum+= v[j];
				} else break;
			}

			if(j<0) {

			} else if(j==0) {

			} else {
				
			}
		}

	}

}