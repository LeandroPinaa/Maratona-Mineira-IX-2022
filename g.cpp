#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(s[0]=='.'){
        cout << "-1\n";
        return 0;
    }
    bool chegou=true;
    int carga=1, pulos=0, usolido=0;
    bool buraco=false;
    for(int i=1; i<s.size(); i++){
        if(s[i]=='x'){
        if(buraco){
        buraco=false;
        if(usolido+carga+1>=i){
            carga=1;
            pulos++;
        }
        else{
            chegou=false;
            break;
        }
        }
        else{
            carga++;
        }
        }
        else{
            if(buraco==false){
            buraco=true;
            usolido=i-1;
            }
        }
    }
    if(chegou)cout<<pulos<<endl;
    else cout<<"-1\n";
}