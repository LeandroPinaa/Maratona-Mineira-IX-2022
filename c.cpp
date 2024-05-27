#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 100005
#define MOD 1000000007
#define int long long
#define pii pair<int,int>
#define INF 1e18
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define m (l+r)/2

int soma[NMAX],v[NMAX];

int32_t main(){ faster
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];
    soma[1] = v[1];
    soma[2] = v[2];
    soma[3] = v[1]+v[3];
    int ans = max({soma[1],soma[2],soma[3]});
    for(int i=4;i<=n;i++){
        soma[i] = max(soma[i-3]+v[i],soma[i-2]+v[i]);
        ans = max(ans,soma[i]);
    }
    cout << ans << '\n';
}