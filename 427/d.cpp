#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 2e5+7;
vector<int> graph[MAXN];
char dp[MAXN][25];

void solve(){
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < n; i++) graph[i].clear();
    string s; cin >> s;
    //memset(dp, 'C', sizeof(dp));
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
    }

    k *= 2;
    for(int i = 0; i < n; i++){
        dp[i][k] = s[i];
    }

    for(int i = k-1; i >= 0; i--){
        for(int v = 0; v < n; v++){
            char p;
            if(i&1) p = 'B';
            else p = 'A';
            int cnt = 0;
            //cout << i << " " << v << " " << p << endl;
            for(auto u : graph[v]){
                //if(k == 3 && v == 2) cout << dp[u][i+1] << " ";
                if(dp[u][i+1] == p) cnt++;
            }
           //if(k == 3 && v == 2) cout << endl;
            if(cnt) dp[v][i] = p;
            else dp[v][i] = (p == 'A' ? 'B' : 'A');
        }
    }

    // cout << k << "  " << n << endl;
    // for(int i = 0; i <= k; i++){
    //     for(int v = 0; v < n; v++){
    //         cout << dp[v][i] << " ";
    //     }
    //     cout << endl;
    // }

    if(dp[0][0] == 'A') cout << "Alice\n";
    else cout << "Bob\n";
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}