#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 505
#define MOD 1000000007
#define int long long
#define pii pair<int,int>
#define INF 1e18
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>


int N, M;
int eixox[]={0,-1,-1,-1,0,1,1,1};
int eixoy[]={-1,-1,0,1,1,1,0,-1};
int m[NMAX][NMAX];

bool dentro(int ex, int ey){
    if(ex>=1 && ex<=N){
        if(ey>=1 && ey<=M)return true;
    }
    return false;
}


int32_t main(){ faster
     cin>>N>>M;
     for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
          cin>>m[i][j];
        }
     }
     int x, y;
     cin>>x>>y;
     if(N==1 && M==1){
        cout<<m[1][1]<<endl;
        return 0;
     }
     int maior=-INF;
     int X, Y, rest, distri, vizi, maiore, cx, cy;
    int consultas = N+M;
    while(consultas--){
        vizi=0;
        maiore=-INF;
        for(int k=0; k<8; k++){
            X=x+eixox[k];
            Y=y+eixoy[k];
            if(dentro(X,Y)) vizi++;
        }
        rest = m[x][y]%vizi;
        distri=m[x][y]/vizi;
        m[x][y] = rest;
        //cout << m[x][y] << '\n';
        //cout << "distri = " << distri << '\n';
        for(int k=0; k<8; k++){
            X=x+eixox[k];
            Y=y+eixoy[k];
            if(dentro(X,Y)){
                m[X][Y]+=distri;
                if(maiore<m[X][Y]){
                    maiore=m[X][Y];
                    cx=X;
                    cy=Y;
                }
            }
        }
        x=cx;
        y=cy;
    }
     for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
             if(maior<m[i][j])maior=m[i][j];
        }
     }
     cout<<maior<<'\n';
}
/*
3 3
0 0 0
0 24 0
0 0 0
2 2
*/