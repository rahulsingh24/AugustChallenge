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
    ll idx;
    node() {
        value=-1;
        idx=-1;
    }
}tree[500000];


void merge(node &ans,node &left,node &right)
{
    if(left.value>right.value) {
        ans.value = left.value;
        ans.idx = left.idx;
    } else if(left.value<right.value) {

        ans.value = right.value;
        ans.idx = right.idx;
    } else {
        if(a[left.idx]>a[right.idx]) {
            ans.value = right.value;
            ans.idx = right.idx;
        } else {
            ans.value = left.value;
            ans.idx = left.idx;
        }
    }
}

void build(ll i,ll left,ll right)
{
    if(left==right)
    {
        tree[i].value = b[left];
        tree[i].idx = left;

    }
    else
    {
        ll mid = (right+left)/2;
        build(2*i+1,left,mid);
        build(2*i+2,mid+1,right);
        merge(tree[i],tree[2*i+1],tree[2*i+2]);
    }
}


void update(ll i,ll left,ll right, ll val,ll idx)
{

    if(left==right)
    {
            b[idx] = val;
            tree[i].value = val;
            tree[i].idx = idx;
            return;
    }

        ll mid = (right+left)/2;
        if(left<=idx && idx<=mid)
        update(2*i+1,left,mid,val,idx);
        if(mid+1<=idx && idx<=right)
        update(2*i+2,mid+1,right,val,idx);
        merge(tree[i],tree[2*i+1],tree[2*i+2]);
}

node query(ll i,ll left,ll right,ll start,ll end)
{
    if(left>right|| left>end || start>right)
        return node();

    if(start<=left && right<=end)
    {
        return tree[i];
    }

    ll mid = (right+left)/2;
    node leftanswer= query(2*i+1,left,mid,start,end);
    node rightanswer= query(2*i+2,mid+1,right,start,end);
    //  merge(tree[i],tree[2*i],tree[2*i+1]);
// cout<<"leftanswer.value = "<<leftanswer.value<<" rightanswer.value = "<<rightanswer.value<<endl;
    if(leftanswer.value<rightanswer.value) return rightanswer;
    else if(leftanswer.value>rightanswer.value) return leftanswer;
    else if(leftanswer.value==rightanswer.value && a[leftanswer.idx]>a[rightanswer.idx]) {
        // cout<<"leftanswer.value2 = "<<leftanswer.value<<" rightanswer.value2 = "<<rightanswer.value<<endl; 
     return rightanswer;
    }

    return leftanswer;
}


node x;
ll idx,sum=0;
ll mn;  
bool fun(ll k) {
    for(int i=0;i<n;++i) b[i]=0;
    build(0,0,n-1);

    mn = v[0].first;
    int j=0;
    while(v[j].first==mn) {
        update(0,0,n-1,1,v[j].second);
        // cout<<"j = "<<j<<endl;
        j++;
    }

    // cout<<"k = "<<k<<endl;
    for(ll i=j;i<n;++i) {
        idx = v[i].second;
        // cout<<"first = "<<v[i].first<<" second = "<<idx<<endl;
        x = query(0,0,n-1,max(0,idx-k),min(n-1,idx+k));
        if(x.value==0) {
             update(0,0,n-1,1,idx);
         } else {
            if(v[i].first==a[x.idx])
                update(0,0,n-1,x.value,idx);
            else 
                update(0,0,n-1,x.value+1,idx);
         }

         // for(ll i=0;i<n;++i) 
         //      cout<<b[i]<<" ";
         //  cout<<endl;
    }

    /*if(v[i]==v[i+1]) {
            r=i;
            vector<pair<ll,ll> > dh;
            while(v[r]==v[r+1]) {
                x = query(0,0,n-1,max(0,r+1-k),min(n-1,r+1+k));
                dhan = max(dhan,x.value);
                dh.push_back(mp(x.value,x.idx));
                r--;
            }
            x = query(0,0,n-1,max(0,r+1-k),min(n-1,r+1+k));
            dhan = max(dhan,x.value);
            dh.push_back(mp(x.value,x.idx));

        }*/

    
    // int l,r;
    // ll dhan=0;
    sum=0;
    // cout<<"-----------update--------"<<endl;
    for(int i=n-2;i>=0;--i) {
       idx = v[i].second;
       if(v[i].first==v[i+1].first) {
        x = query(0,0,n-1,max(0,idx-k),min(n-1,idx+k));
       if(v[i].first==a[x.idx] && b[idx]<b[x.idx]) {
        update(0,0,n-1,max(b[idx],b[x.idx]),idx);
       }
       }
       
        sum+=b[i];
    }

    sum += b[n-1];

    /*for(int i=0;i<=n-1;++i) {
        x = query(0,0,n-1,max(0,i-k),min(n-1,i+k));
        if(a[i]==a[x.idx] && x.value!=b[i]) {
            update(0,0,n-1,max(x.value,b[i]),i);
        } 
         sum+=b[i];
    }*/

     
    // cout<<"k = "<<k<<endl;
    // for(ll i=0;i<n;++i) {
   //     cout<<b[i]<<" ";
        // sum+=b[i];
    // }
    // cout<<endl;

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