#include <bits/stdc++.h>
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

ll max(ll x, ll y) {
    return x>y?x:y;
}
ll min(ll x, ll y) {
    return x<y?x:y; 
}

ll b[100020];
ll n,s,p,pre;
ll a[100020];
vector<pair<ll,ll> > v;

struct node{
    ll value;
    node() {
        value=-1;
    }
}tree[500000];

void build()
{
    for (int i=0; i<n; i++) {
         tree[n+i].value = b[i];
    }  
       
    for (int i = n - 1; i > 0; --i)  {
        tree[i].value = max(tree[i<<1].value,tree[i<<1|1].value);
    }    
}


void update(ll val,ll idx)
{
    b[idx]=val;
    tree[idx+n].value = val;
    idx = idx+n;
     
    for (int i=idx; i > 1; i >>= 1) {
        tree[i>>1].value = max(tree[i].value,tree[i^1].value);
    }
}

ll query(ll l,ll r)
{
    ll res =-1;
    r++;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
        if(l&1) {
            res = max(res,tree[l++].value);
        }

        if(r&1) {
           res = max(res,tree[--r].value);
        }
    }

    return res;

}


node x;
ll idx,sum=0;
ll mn,mm;  
bool fun(ll k) {
    for(int i=0;i<n;++i) b[i]=0;
    build();

    sum=0;

    // cout<<"k = "<<k<<endl;
    // for(int i=0;i<=2*n;i++) {
    //     cout<<"i = "<<i<<" "<<tree[i].value<<" "<<tree[i].idx<<endl;
    // }

    // cout<<"v"<<endl;
    // for(int i=0;i<v.size();i++) {
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }

    for(int lol=0;lol<n;) {
        mn = v[lol].first;
        int j=lol;
        while(v[j].first==mn && j<v.size()) {
            // cout<<"j = "<<j<<" "<<v[j].first<<endl;
            j++;
        }

        vector<pair<ll,ll> > w;

        for(int i=lol;i<j;i++) {
            int l = max(0,v[i].second-k);
            int r = min(n-1,v[i].second+k);
            ll adh = query(l,r);
            w.pb(mp(adh+1,v[i].second));
        }

        // cout<<"size = "<<w.size()<<endl;

        for(int i=0;i<w.size();) {
            int pp = i+1;
            while(pp<w.size() && w[pp].second<=w[pp-1].second+k)
                pp++;
            mm = -1;
            for(int u=i;u<pp;u++) {
                mm = max(mm,w[u].first);
            }

            for(int u=i;u<pp;u++) {
                update(mm,w[u].second);
                sum+=mm;
                // cout<<"mm = " <<mm<<" sum = "<<sum<<endl;
            }

            i = pp;
        }
        lol = j;
    }


    // cout<<"k = "<<k<<endl;
    //  for(ll i=0;i<n;++i) 
    //       cout<<b[i]<<" ";
    //   cout<<endl;

    if(sum<=s) return true;

    return false;
}

int main() {
    int t;
    scanf("%d",&t);
    //ll INF = 1000000007;
    while(t--) {
       scanf("%lld %lld",&n,&s);

       v.clear();
       ll x;
       for(ll i=0;i<n;++i) {
        scanf("%lld",&x);
        a[i]=x;
        v.pb(mp(x,i));
       } 

       if(s<n) {
        printf("%d\n", 0);
       } else {
           sort(v.begin(),v.end());

           ll answer=1;
           
           ll r=n,l=1;
           while(l<=r) {
                ll mid = (l+r)/2;
                if(fun(mid)) {
                    l=mid+1;
                    answer = max(answer,mid+1);
                } else {
                    r=mid-1;
                }
           }

           printf("%lld\n", answer);
        }

    }
}