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

ll PowMod(ll n, ll m, ll md)
{
    // cout<<"n = "<<n<<" m = "<<m<<" md = "<<md<<endl;
    ll ret = 1;
    ll a = m;
    // ll md = mdd;
    ll t;
    // cout<<"a = "<<a<<" md = "<<md<<endl;
    while (n > 0) {
        if (n & 1) ret = (md+((md+ret)%md)*1ull*((md+a)%md))%md;
        t = (md+a)%md;
        // cout<<"t = "<<t<<endl;
        a = (md+((t)*1ull*(t)))%md;
        // if(a==0) return 0;
        // cout<<"ret = "<<ret<<" a = "<<a<<endl;
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
    //ll INF = 1000000007;
    while(t--) {
        ll A,B,n;
        cin>>A>>B>>n;

        ll b = abs(A-B);
        // cout<<"dhanraj b ="<<b<<endl;

        if(b>1) {
            A = (b+A)%b;
            B = (b+B)%b;
            ll t = PowMod(n,A,b);
            ll p = PowMod(n,B,b);
            // cout<<"t = "<<t<<" p = "<<p<<endl;
            ll a = (b+((b+t)%b+(b+p)%b))%b;
            // cout<<"a = "<<a<<endl;
            ll answer = (INF+gcd(a,b))%INF;
            cout<<answer<<endl;
            continue;
        }
        if(b==0) {
            A = (INF+A)%INF;
            ll answer = (INF+(INF+(INF+PowMod(n,A,INF))%INF*(2%INF))%INF)%INF;
            // cout<<"b = 0"<<endl;
            cout<<answer<<endl;
            continue;
        }
        if(b==1) cout<<1<<endl;
    }
}