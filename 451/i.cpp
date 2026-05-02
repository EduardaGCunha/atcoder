#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int INF = 1e18;
const int MAXN = 17;
//qtd de transacoes, debt atual
pair<int, int> dp[MAXN][(1<<MAXN)];

signed main(){
    fastio;
    int n, m; cin >> n >> m;
    vector<int> debts(n, 0);
    for(int i = 0; i < m; i++){
        int p, k, v; 
        cin >> p >> v >> k;
        p--;
        for(int j = 0; j < k; j++){
            int x; cin >> x;
            x--;
            debts[x] -= v;
        }
        debts[p] += k*v;
    }

    int tot = (1<<n);
    vector<int> sums(tot, 0), dp(tot, 0);
    for(int mask = 0; mask < tot; mask++){
        for(int i = 0; i < n; i++){
            if(mask&(1<<i)) sums[mask] += debts[i];
        }
    }
    for(int mask = 1; mask < tot; mask++){
        for(int i = 0; i < n; i++){
            if(mask & (1<<i)) dp[mask] = max(dp[mask], dp[mask^(1<<i)]);
        }   

        if(!sums[mask]) dp[mask]++;
    }
    
    cout << n - dp[tot-1] << endl;
}