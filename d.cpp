#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 405
#define MOD 1000000007
#define int long long
#define pii pair<int,int>
#define INF 1e18
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define mx (lx+rx)/2
#define my (ly+ry)/2

int t[NMAX<<2][NMAX<<2];
int n,m;

void buildy(int ix, int lx, int rx, int iy, int ly, int ry){
    if(ly==ry){
        if(lx==rx) t[ix][iy] = INF;
        else t[ix][iy] = max(t[ix*2][iy],t[ix*2+1][iy]);
        return;
    }
    buildy(ix,lx,rx,iy*2,ly,my);
    buildy(ix,lx,rx,iy*2+1,my+1,ry);
    t[ix][iy] = max(t[ix][iy*2],t[ix][iy*2+1]);
}

void buildx(int ix, int lx, int rx){
    if(lx==rx){
        buildy(ix,lx,rx,1,1,m);
        return;
    }
    buildx(ix*2,lx,mx);
    buildx(ix*2+1,mx+1,rx);
    buildy(ix,lx,rx,1,1,m);
}

void updatey(int ix, int lx, int rx, int iy, int ly, int ry, int x, int y, int z){
    if(ly==ry){
        if(lx==rx) t[ix][iy] = z;
        else t[ix][iy] = max(t[ix*2][iy],t[ix*2+1][iy]);
        return;
    }
    if(y<=my) updatey(ix,lx,rx,iy*2,ly,my,x,y,z);
    else updatey(ix,lx,rx,iy*2+1,my+1,ry,x,y,z);    
    t[ix][iy] = max(t[ix][iy*2],t[ix][iy*2+1]);
}

void updatex(int ix, int lx, int rx, int x, int y, int z){
    if(lx==rx){
        updatey(ix,lx,rx,1,1,m,x,y,z);
        return;
    }
    if(x<=mx) updatex(ix*2,lx,mx,x,y,z);
    else updatex(ix*2+1,mx+1,rx,x,y,z);
    updatey(ix,lx,rx,1,1,m,x,y,z);
}

int rangequeryy(int ix, int iy, int ly, int ry, int py, int qy){
    if(py<=ly&&ry<=qy) return t[ix][iy];
    if(py>ry || qy<ly) return -INF;
    return max(rangequeryy(ix,iy*2,ly,my,py,qy),rangequeryy(ix,iy*2+1,my+1,ry,py,qy));
}

int rangequeryx(int ix, int lx, int rx, int px, int qx, int py, int qy){
    if(px<=lx&&rx<=qx) return rangequeryy(ix,1,1,m,py,qy);
    if(px>rx || qx<lx) return -INF;
    return max(rangequeryx(ix*2,lx,mx,px,qx,py,qy),rangequeryx(ix*2+1,mx+1,rx,px,qx,py,qy));
}

int32_t main(){ faster
    int k,q;
    cin >> n >> m >> k >> q;
    buildx(1,1,n); //builda tudo INF
    while(q--){
        int a,b,value;
        cin >> a >> b >> value;
        updatex(1,1,n,a,b,value);
    }
    int ans = INF;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i+k-1<=n && j+k-1<=m){
                ans = min(ans,rangequeryx(1,1,n,i,i+k-1,j,j+k-1));
            }
        }
    }
    cout << (ans==INF ? -1 : ans) << '\n';
}
/*

*/