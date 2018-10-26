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
    while(t--) {
        ll n;
        cin>>n;

        int cbits=0;

        if(n==1) {
            cout<<2<<endl;
            continue;
        }

        ll p = n;
        while(p) {
            p = p&(p-1);
            cbits++;
        }
        if(cbits==2) {
            cout<<0<<endl;
            continue;
        }
        if(cbits==1) {
            cout<<1<<endl;
            continue;
        }

        ll low=n;
        int c=0;
        while(1) {
            low = low&(low-1);
            c++;
            if(cbits-c==2) break;
        }

        ll up=0;
        c=0;
        int i=32;
        for(;i>=0;i--) {
            if(n&(1<<i)) {
                c++;
                up = up+(1<<i);
                if(c==2) break;
            }
        }

        c=0;
        up = up+(1<<i);
        p = up;
        while(p) {
            p = p&(p-1);
            c++;
        }

        if(c==2) {
            int answer = min(abs(n-up),abs(n-low));
            cout<<answer<<endl;
        } else {
            up++;
            int answer = min(abs(n-up),abs(n-low));
            cout<<answer<<endl;
        }
        
    }
}