#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 500005
#define MOD 1000000007
#define int long long
#define pii pair<int,int>
#define INF 1e18
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

int n,m,k,cor[4];
vector<int>linhaoucoluna;

int quantoscolore(int c){
    // lembrando q esse vector pegou indexado-0
    int tam = linhaoucoluna.size();
    int precisa = (n*m) - cor[c];
    bool temnomeio = true;
    for(int i=tam-k-1;i<=k;i++)
		if(linhaoucoluna[i] != c)
			temnomeio = false;
    if(temnomeio) precisa += 2;
    return precisa;
}


int32_t main(){ faster
    int qtdmaiorcor=0;
    cin >> n >> m >> k;
    vector<vector<int>>mat(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> mat[i][j];
            int x = mat[i][j];
            cor[x]++;
            qtdmaiorcor = max(qtdmaiorcor,cor[x]);
        }
    }
    if(n==1 || m==1){
        int len = max(n,m);
        int minimo = len/2;
        if(k < minimo || k >= len) cout << "-1\n";
        else{
            // só pegando o vetor
            if(m > n) for(int i=1;i<=m;i++) linhaoucoluna.push_back(mat[1][i]);
            else for(int i=1;i<=n;i++) linhaoucoluna.push_back(mat[i][1]);
            int ans = min({quantoscolore(1),quantoscolore(2),quantoscolore(3)});
            cout << ans << '\n';
        }
    }
    else{
        if(k == (n*m)-1) cout << (n*m) - qtdmaiorcor << '\n';
        else cout << "-1\n";
    }    
}