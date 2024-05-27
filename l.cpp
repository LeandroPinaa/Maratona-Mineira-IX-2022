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



int32_t main(){ faster
    string s;
    cin >> s;
    int tam = s.size();
    int n,letras=0,first=0,distoposta=1;
    bool alterna = false;
    cin >> n;
    if(n==1 || n==s.size()){
        cout << s << '\n';
        return 0;
    }
    int dist = (n*2) - 3;
    vector<vector<char>>m(n,vector<char>(tam,'.'));
    for(int i=0;i<n;i++){
        if(i!=0) alterna = false;
        for(int j=first;j<tam;j++){
            if(i==0){
                if(letras < tam) m[i][j] = s[letras++]; 
                else break; //ja pegou todas
                int distt = dist;
                while(distt--){
                    j++;
                    if(j==tam) break;
                }
            }
            else{
                if(letras < tam) m[i][j] = s[letras++];
                else break; //ja pegou todas
                int distt;
                if(!alterna){
                    distt = dist;
                    alterna = true;
                } 
                else{
                    distt = distoposta;
                    alterna = false;
                }
                while(distt--){
                    j++;
                    if(j==tam) break;
                }
            }
        }
        dist -= 2;
        first++;
        if(i>0) distoposta += 2;
        if(dist<0) break; //só falta a ultima linha garantido
    }
    for(int j=first;j<tam;j++){
        if(letras < tam) m[n-1][j] = s[letras++];
        else break; //ja pegou todas
        int distt = (n*2) - 3;
        while(distt--){
            j++;
            if(j==tam) break;
        }
    }
    string ans = "";
    for(int j=0;j<tam;j++){
        for(int i=0;i<n;i++){
            if(m[i][j]!='.'){
                ans.push_back(m[i][j]);
                break;
            }
        }
    }
    cout << ans << '\n';
}
/*
PUAQEOEIODJ
4
*/