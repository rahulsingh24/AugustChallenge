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
        string a,b;
        cin>>a>>b;
        
        int x=0,o=0;
        if(a[0]=='b' && x!=2) x++;
        if(a[0]=='o' && o!=1) o++;
        if(a[1]=='b' && x!=2) x++;
        if(a[1]=='o' && o!=1) o++;
        if(a[2]=='b' && x!=2) x++;
        if(a[2]=='o' && o!=1) o++;
        if(x==2 && o==1) {
            cout<<"yes"<<endl;
            continue;
        }
        x=0,o=0;
        if(a[0]=='b' && x!=2) x++;
        if(a[0]=='o' && o!=1) o++;
        if(a[1]=='b' && x!=2) x++;
        if(a[1]=='o' && o!=1) o++;
        if(b[2]=='b' && x!=2) x++;
        if(b[2]=='o' && o!=1) o++;
        if(x==2 && o==1) {
            cout<<"yes"<<endl;
            continue;
        }
        x=0,o=0;
        if(a[0]=='b' && x!=2) x++;
        if(a[0]=='o' && o!=1) o++;
        if(b[1]=='b' && x!=2) x++;
        if(b[1]=='o' && o!=1) o++;
        if(a[2]=='b' && x!=2) x++;
        if(a[2]=='o' && o!=1) o++;
        if(x==2 && o==1) {
            cout<<"yes"<<endl;
            continue;
        }
        x=0,o=0;
        if(b[0]=='b' && x!=2) x++;
        if(b[0]=='o' && o!=1) o++;
        if(a[1]=='b' && x!=2) x++;
        if(a[1]=='o' && o!=1) o++;
        if(a[2]=='b' && x!=2) x++;
        if(a[2]=='o' && o!=1) o++;
        if(x==2 && o==1) {
            cout<<"yes"<<endl;
            continue;
        }
        x=0,o=0;
        if(a[0]=='b' && x!=2) x++;
        if(a[0]=='o' && o!=1) o++;
        if(b[1]=='b' && x!=2) x++;
        if(b[1]=='o' && o!=1) o++;
        if(b[2]=='b' && x!=2) x++;
        if(b[2]=='o' && o!=1) o++;
        if(x==2 && o==1) {
            cout<<"yes"<<endl;
            continue;
        }
        x=0,o=0;
        if(b[0]=='b' && x!=2) x++;
        if(b[0]=='o' && o!=1) o++;
        if(a[1]=='b' && x!=2) x++;
        if(a[1]=='o' && o!=1) o++;
        if(b[2]=='b' && x!=2) x++;
        if(b[2]=='o' && o!=1) o++;
        if(x==2 && o==1) {
            cout<<"yes"<<endl;
            continue;
        }
        x=0,o=0;
        if(b[0]=='b' && x!=2) x++;
        if(b[0]=='o' && o!=1) o++;
        if(b[1]=='b' && x!=2) x++;
        if(b[1]=='o' && o!=1) o++;
        if(a[2]=='b' && x!=2) x++;
        if(a[2]=='o' && o!=1) o++;
        if(x==2 && o==1) {
            cout<<"yes"<<endl;
            continue;
        }
        x=0,o=0;
        if(b[0]=='b' && x!=2) x++;
        if(b[0]=='o' && o!=1) o++;
        if(b[1]=='b' && x!=2) x++;
        if(b[1]=='o' && o!=1) o++;
        if(b[2]=='b' && x!=2) x++;
        if(b[2]=='o' && o!=1) o++;
        if(x==2 && o==1) {
            cout<<"yes"<<endl;
            continue;
        }

        cout<<"no"<<endl;

    }
}