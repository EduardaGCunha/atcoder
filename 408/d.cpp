#include <bits/stdc++.h>
using namespace std;

/*
melhor escolha entre 
    pegar o maior intervalo de 1s seguidos e transformar os outros em 0
    transformar alguns 0 em 1 e alguns 1s em 0
    
*/

#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define int long long

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int b[n+1];
    int tot = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') b[i+1] = b[i] + 1;
        else {
            b[i+1] = b[i] - 1;
            tot++;
        }
    }

    int ans = 0, mx = 0;
    for(int i = 0; i <= n; i++){
        ans = min(ans, b[i] - mx);
        mx = max(mx, b[i]);
    }
    cout << tot + ans << endl;
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}