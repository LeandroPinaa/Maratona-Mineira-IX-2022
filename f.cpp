#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 200005
#define MOD 1000000007
#define int long long
#define pii pair<int,int>
#define INF 1e18
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define m (l+r)/2

int32_t main(){ faster
    int N, g = 0, gMin = 0, gMax = 0;
    string s;
    cin>>N;
    cin>>s;

    for(int i=0; i<s.length(); i++) {
        if(s[i]=='D') {
            g+=N;
            if(g>gMax) gMax = g;
        }
        else {
            g-=N;
            if(g<gMin) gMin = g;
        }
    }
    if(gMax-gMin < 360) cout<<"N";
    else cout<<"S";
    return 0;
}