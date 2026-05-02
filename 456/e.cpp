#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int MOD = 998244353;

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (a*res)%MOD;
        a = (a*a)%MOD;
        b >>=1; 
    }
    return res;
}

/*
se forem diferentes
    ans += tam
    tam++
se forem iguais
    ans++ (so contribui 1 vez)

abccccccc
ans = 1 + 2 + 3
*/

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int tam; cin >> tam;
    vector<string> hol(n);
    //v, dia
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(tam+1, 0));
    for(int i = 0; i < n; i++){
        cin >> hol[i];
    }

    bool ans = false;
    auto dfs = [&](int v, int d, auto &dfs) -> void {
        if(ans) return;
        visited[v][d] = 1;
        vector<int> pote = graph[v];
        pote.push_back(v);
        for(auto u : pote){
            int nxt = (d+1)%tam;
            if(hol[u][nxt] == 'x') continue;
            if(!visited[u][nxt]){
                dfs(u, nxt, dfs);
            }else if(visited[u][nxt] == 1){
                ans = true;
                return;
            }
        }
        visited[v][d] = 2;
    };

    for(int i = 0; i < n; i++){
        if(!visited[i][0] && hol[i][0] == 'o') dfs(i, 0, dfs);
    }

    if(ans) cout << "Yes\n";
    else cout << "No\n";
}

signed main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}