#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <list>
#include <map>
#include <utility>
#include <vector>
#include <set>
#include <string>
#include <queue>
using namespace std;
 
#define ll long long int
#define INF 1000000007
#define INFLL 1000000000000000011LL
#define pb(x) push_back(x)
#define mp make_pair
#define fi first
#define se second
#define vi vector
#define gtl(x) getline(cin, (x))
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)((a).size())
#define setv(x,a) memset(x,a,sizeof(x))
#define ull unsigned long long int 

long long modmult(long long a,long long b,long long mod)
{
    if (a == 0 || b < mod / a)
        return (a*b)%mod;
    long long sum;
    sum = 0;
    while(b>0)
    {
        if(b&1)
            sum = (sum + a) % mod;
        a = (2*a) % mod;
        b>>=1;
    }
    return sum;
}
 
ll PowMod(ll n, ll m, ll md)
{
    ll ret = 1;
    ll a = m;
    while (n > 0) {
        if (n & 1) ret = modmult(ret,a,md);
        a = modmult(a,a,md);
        n >>= 1;
    }
    return ret;
}
 
ll gcd(ll a, ll b) {
            if (a == 0) return b;
            if (b == 0) return a;
            if (a < 0) return gcd(-1 * a, b);
            if (b < 0) return gcd(a, -1 * b);
            if (a > b) return gcd(b, a);
            return gcd(b%a, a);
}
 
int main() {
    int t;
    cin>>t;
    // ll INF = 1000000007;
    while(t--) {
        ll A,B,n;
        cin>>A>>B>>n;
 
        ll b = A-B;
 
        if(b>1) {
            A = A%b;
            B = B%b;
            ll a = (PowMod(n,A,b)*2)%b;
            ll answer = (gcd(a,b)%INF);
            cout<<answer<<endl;
            continue;
        }
        if(b==0) {
            A = A%INF;
            // cout<<INF<<" "<<A<<endl;
            ll answer = (PowMod(n,A,INF)*2)%INF;
            cout<<answer<<endl;
            continue;
        }
        if(b==1) cout<<1<<endl;
    }
} 