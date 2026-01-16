#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

int grid[9][9];
int dp[9][(1<<9)+7];
int n, m; 

//retorna o custo da mudanca atual
int custo(int col, int bitmask){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        //cout << grid[i][col] << " " << (bitmask&(1<<i)) << endl;
        //se estiver com 0, entao pinto para branco
        if(!(bitmask&(1<<i))){
            //passando de preto pra branco
            if(grid[i][col] == 1) cnt++;
        }else{
            //branco pra preto - nao pode
            if(grid[i][col] == 0) return 1e5;
        }
    }
    return cnt;
}

bool check(int mask1, int mask2){
    for(int i = 0; i < n-1; i++){
        if(!(mask1&(1<<i)) || !(mask1&(1<<(i+1))) || !(mask2&(1<<i)) || !(mask2&(1<<(i+1)))) continue;
        return false;
    }
    return true;
}

void solve(){
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char a; cin >> a;
            if(a == '#') grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }

    //cout << custo(0, 23) << endl;

    for(int j = 0; j < (1<<n); j++){
        dp[0][j] = custo(0, j);
        //cout << dp[0][j] << " ";
        // for(int i = 0; i < n; i++){
        //     if(j&(1<<i)) cout << 1;
        //     else cout << 0;
        // }
        //cout << endl;
    }

    //para cada coluna
    for(int i = 1; i < m; i++){
        //calculando o custo
        for(int mask = 0; mask < (1<<n); mask++){
            dp[i][mask] = custo(i, mask);
            int minimum = 1e5;
            for(int mask2 = 0; mask2 < (1<<n); mask2++){
                if(check(mask, mask2)){
                    minimum = min(minimum, dp[i-1][mask2]);
                }
            }
            dp[i][mask] += minimum;
        }
    }

    int ans = 1e5;
    for(int mask = 0; mask < (1<<n); mask++){
        ans = min(ans, dp[m-1][mask]);
    }
    cout << ans << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}