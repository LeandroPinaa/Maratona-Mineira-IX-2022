#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 1005
#define MOD 1000000007
#define int long long
#define pii pair<int,int>
#define INF 1e18
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

char mat[NMAX][NMAX];
int dist[NMAX][NMAX];
int n,m,consegue;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int mdc(int a, int b){
    if(a==0) return b;
    return mdc(b%a,a);
}

bool dentro(int x, int y){
    if(x>=1&&x<=n&&y>=1&&y<=m) return true;
    return false;
}

void BFS(int u, int v){
    dist[u][v] = 0;
    queue<pii>fila;
    fila.push({u,v});
    while(!fila.empty()){
        auto [x,y] = fila.front(); fila.pop();
        for(int d=0;d<4;d++){
            int X = x+dx[d];
            int Y = y+dy[d];
            if(dentro(X,Y) && mat[X][Y]=='.' && dist[X][Y]==-1){
                dist[X][Y] = dist[x][y]+1;
                fila.push({X,Y});
            }
        }
    }
}

int32_t main(){
    int segundos,x,y,tot=0;
    cin >> n >> m >> segundos >> x >> y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> mat[i][j];
            if(mat[i][j]=='.') tot++;
        }
    }
    memset(dist,-1,sizeof dist);
    BFS(x,y);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mat[i][j]=='.' && dist[i][j]!=-1 && dist[i][j]<=segundos){
                consegue++;
            }
        }
    }
    int MDC = mdc(consegue,tot);
    cout << consegue/MDC << " " << tot/MDC << '\n';
}