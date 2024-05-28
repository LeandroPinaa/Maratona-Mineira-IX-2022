#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 500005
#define MOD 1000000007
#define int long long
#define pii pair<int,int>
#define INF 1e9
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define m (l+r)/2

typedef struct{
    int mn,mx,dd; //drawdown
    pii pdd; //percentual drawdown caso base (0,1) (0 pq eh o caso base pra drawdown e 1 pq pegaria pelo menos só o primeiro)
}node;
node t[NMAX<<2];
int v[NMAX];

node emptynode(){
    node resp;
    resp.mx = resp.dd = 0;
    resp.mn = INF;
    resp.pdd = {0,1};
    return resp;
}

pii paircomb(pii a, pii b){
    if( a.first*b.second > a.second*b.first ) return a;
    return b;
}
/*
se quero ver qual a maior fração abaixo:
a > c
b   d
basta fazer: a*d > b*c
*/

node combination(node a, node b){
    node resp;
    resp.mn = min(a.mn,b.mn);
    resp.mx = max(a.mx,b.mx);
    resp.dd = max({a.dd,b.dd,a.mx - b.mn});
    resp.pdd = paircomb(paircomb(a.pdd,b.pdd),{a.mx-b.mn,a.mx});
    return resp;
}

void build(int i, int l, int r){
    if(l==r){
        t[i].mn = t[i].mx = v[l];
        t[i].dd = 0;
        t[i].pdd = {0,1};
        return;
    }
    build(i*2,l,m);
    build(i*2+1,m+1,r);
    t[i] = combination(t[i*2],t[i*2+1]);
}

node range_query(int i, int l, int r, int ql, int qr){
    if(ql<=l&&r<=qr) return t[i];
    if(ql>r || qr<l) return emptynode();
    return combination(range_query(i*2,l,m,ql,qr),range_query(i*2+1,m+1,r,ql,qr));
}

int mdc(int a, int b){
    if(a==0) return b;
    return mdc(b%a,a);
}

int32_t main(){ faster
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];
    build(1,1,n);
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        node ans = range_query(1,1,n,a,b);  
        int MDC = mdc(ans.pdd.first,ans.pdd.second);
        cout << ans.dd << " " << ans.pdd.first/MDC << " " << ans.pdd.second/MDC << '\n';
    }
}