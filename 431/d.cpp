#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define endl '\n'

const ll INF = 1e18;
const int MAXN = 507;
const int MAXM = 125005;
ll h[MAXN], w[MAXN], b[MAXN];
ll dp[MAXN][MAXM];

ll n, tot;

ll pd(int idx, ll weight){
    if(2*weight > tot) return -INF;
    if(idx == n) return 0;

    if(dp[idx][weight] != -1) return dp[idx][weight];

    return dp[idx][weight] = max(pd(idx+1, weight + w[idx]) + h[idx], pd(idx+1, weight) + b[idx]);
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> w[i] >> h[i] >> b[i];
        tot += w[i];
    }
    
    memset(dp, -1, sizeof(dp));

    cout << pd(0, 0) << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}